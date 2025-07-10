#pragma once
#include "pch.h"
#include <functional>
#include <concepts>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

namespace TEngine
{
    template<typename INST>
    concept ISCLASS = std::is_class_v<INST>;

    template <typename ...Args>
    class Delegate
    {
        struct CallbackInfo
        {
            std::shared_ptr<std::function<void(Args...)>> callback;
            void* instance;
            size_t id;
            bool isValid;

            CallbackInfo(std::shared_ptr<std::function<void(Args...)>> cb, void* inst, size_t callbackId)
                : callback(cb), instance(inst), id(callbackId), isValid(true) {
            }
        };

    public:
        Delegate();
        ~Delegate();

        Delegate(const Delegate&) = delete;
        Delegate& operator=(const Delegate&) = delete;

        Delegate(Delegate&& other) noexcept;
        Delegate& operator=(Delegate&& other) noexcept;

    public:
        template<ISCLASS INST>
        size_t addCallback(void* instance, void(INST::* function)(Args...));

        void removeCallback(size_t callbackId);
        void removeAllCallbacks(void* instance);
        void invoke(Args... args);
        void clear();

        bool isEmpty() const { return _callbacks.empty(); }
        size_t getCallbackCount() const { return _callbacks.size(); }

    private:
        std::vector<CallbackInfo> _callbacks;
        size_t _nextId;
        bool _isDestroying;

        void cleanup();
    };

    template<typename ...Args>
    inline Delegate<Args...>::Delegate()
        : _callbacks(), _nextId(0), _isDestroying(false)
    {
    }

    template<typename ...Args>
    inline Delegate<Args...>::~Delegate()
    {
        _isDestroying = true;
        cleanup();
    }

    template<typename ...Args>
    inline Delegate<Args...>::Delegate(Delegate&& other) noexcept
        : _callbacks(std::move(other._callbacks))
        , _nextId(other._nextId)
        , _isDestroying(false)
    {
        other._callbacks.clear();
        other._nextId = 0;
    }

    template<typename ...Args>
    inline Delegate<Args...>& Delegate<Args...>::operator=(Delegate&& other) noexcept
    {
        if (this != &other)
        {
            cleanup();
            _callbacks = std::move(other._callbacks);
            _nextId = other._nextId;
            _isDestroying = false;

            other._callbacks.clear();
            other._nextId = 0;
        }
        return *this;
    }

    template<typename ...Args>
    template<ISCLASS INST>
    inline size_t Delegate<Args...>::addCallback(void* instance, void(INST::* function)(Args...))
    {
        if (_isDestroying) return 0;

        INST* inst = static_cast<INST*>(instance);
        auto bindedFunc = std::make_shared<std::function<void(Args...)>>(
            [inst, function](Args... args)
            {
                (inst->*function)(args...);
            }
        );

        size_t id = _nextId++;
        _callbacks.emplace_back(bindedFunc, instance, id);
        return id;
    }

    template<typename ...Args>
    inline void Delegate<Args...>::removeCallback(size_t callbackId)
    {
        if (_isDestroying) return;

        for (auto& info : _callbacks)
        {
            if (info.id == callbackId)
            {
                info.isValid = false;
                info.callback.reset();
                break;
            }
        }

        // 무효한 콜백들 제거
        _callbacks.erase(
            std::remove_if(_callbacks.begin(), _callbacks.end(),
                [](const CallbackInfo& info) 
                {
                    return !info.isValid;
                }),
            _callbacks.end());
    }

    template<typename ...Args>
    inline void Delegate<Args...>::removeAllCallbacks(void* instance)
    {
        if (_isDestroying) return;

        for (auto& info : _callbacks)
        {
            if (info.instance == instance)
            {
                info.isValid = false;
                info.callback.reset();
            }
        }

        _callbacks.erase
        (
            std::remove_if(_callbacks.begin(), _callbacks.end(),
                [](const CallbackInfo& info) 
                {
                    return !info.isValid;
                }),
            _callbacks.end());
    }

    template<typename ...Args>
    inline void Delegate<Args...>::invoke(Args... args)
    {
        if (_isDestroying) return;

        std::vector<std::shared_ptr<std::function<void(Args...)>>> validCallbacks;
        validCallbacks.reserve(_callbacks.size());

        for (const auto& info : _callbacks) 
        {
            if (info.isValid && info.callback) 
            {
                validCallbacks.push_back(info.callback);
            }
        }

        for (const auto& callback : validCallbacks) {
            if (callback && *callback) 
            {
                try 
                {
                    (*callback)(args...);
                }
                catch (...) 
                {
                }
            }
        }
    }

    template<typename ...Args>
    inline void Delegate<Args...>::clear()
    {
        if (_isDestroying) return;
        cleanup();
    }

    template<typename ...Args>
    inline void Delegate<Args...>::cleanup()
    {
        for (auto& info : _callbacks) 
        {
            info.isValid = false;
            if (info.callback)
            {
                info.callback.reset();
            }
        }

        try 
        {
            _callbacks.clear();
        }
        catch (...)
        {
        }
    }
}
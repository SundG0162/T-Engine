#pragma once
#include "pch.h"
#include <functional>
#include <concepts>

namespace TEngine
{
	template<typename INST>
	concept ISCLASS = std::is_class_v<INST>;

	template <typename ...Args>
	class Delegate
	{
		typedef std::function<void(Args...)> Callback;
	public:
		Delegate();
		~Delegate();
	public:
		template<ISCLASS INST>
		void addCallback(void* instance, void(INST::*function)(Args...));
		template<ISCLASS INST>
		void removeCallback(void* instance, void(INST::* function)(Args...));
		void invoke(Args... args);
	private:
		std::vector<Callback> _callbackVector;
		std::map<void*, std::vector<Callback>> _callbackMap;
	};

	template<typename ...Args>
	inline Delegate<Args...>::Delegate()
	{
	}

	template<typename ...Args>
	inline Delegate<Args...>::~Delegate()
	{
	}


	template<typename ...Args>
	inline void Delegate<Args...>::invoke(Args... args)
	{
		auto removeBegin =
			std::remove_if(_callbackVector.begin(), _callbackVector.end(),
				[&](const Callback& callback) {
					return !callback;
				});
		_callbackVector.erase(removeBegin, _callbackVector.end());
		for (Callback callback : _callbackVector)
		{
			callback(args);
		}
	}

	template<typename ...Args>
	template<ISCLASS INST>
	inline void Delegate<Args...>::addCallback(void* instance, void(INST::* function)(Args...))
	{
		INST* inst = static_cast<INST*>(instance);
		auto bindedFunc = std::bind(function, inst, std::placeholders::_1);
		_callbackVector.push_back(bindedFunc);
		_callbackMap[instance].push_back(bindedFunc);
	}

	template<typename ...Args>
	template<ISCLASS INST>
	inline void Delegate<Args...>::removeCallback(void* instance, void(INST::* function)(Args...))
	{
		if (_callbackMap.find(instance) != _callbackMap.end())
		{
			auto& callbacks = _callbackMap[instance];
			callbacks.erase(
				std::remove_if(callbacks.begin(), callbacks.end(),
					[&](const Callback& cb) {
						return cb.target<void(INST::*)(Args...)>() == &function;
					}),
				callbacks.end()
			);

			_callbackVector.erase(
				std::remove_if(_callbackVector.begin(), _callbackVector.end(),
					[&](const Callback& cb) {
						return cb.target<void(INST::*)(Args...)>() == &function;
					}),
				_callbackVector.end()
			);

			if (callbacks.empty())
				_callbackMap.erase(instance);
		}
	}
}


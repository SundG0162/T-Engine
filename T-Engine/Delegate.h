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
		void addCallback(void* instance, void(INST::* function)(Args...));
		void removeAllCallbacks(void* instance);
		void invoke(Args... args);
	private:
		std::vector<Callback> _callbackVector;
		std::map<void*, std::vector<Callback>> _callbackMap;
	};

	template<typename ...Args>
	inline Delegate<Args...>::Delegate()
		: _callbackVector()
	{
	}

	template<typename ...Args>
	inline Delegate<Args...>::~Delegate()
	{
	}


	template<typename ...Args>
	inline void Delegate<Args...>::removeAllCallbacks(void* instance)
	{
		auto it = _callbackMap.find(instance);
		if (it != _callbackMap.end())
		{
			const auto& instanceCallbacks = it->second;
			_callbackVector.erase(
				std::remove_if(_callbackVector.begin(), _callbackVector.end(),
					[&instanceCallbacks](const Callback& callback) 
					{
						return std::find(instanceCallbacks.begin(), instanceCallbacks.end(), callback) != instanceCallbacks.end();
					}),
				_callbackVector.end());

			_callbackMap.erase(it);
		}
	}

	template<typename ...Args>
	inline void Delegate<Args...>::invoke(Args... args)
	{
		for (size_t i = 0; i < _callbackVector.size();)
		{
			if (_callbackVector[i]) {
				_callbackVector[i](args...);
				++i;
			}
			else {
				_callbackVector.erase(_callbackVector.begin() + i);
			}
		}
	}

	template<typename ...Args>
	template<ISCLASS INST>
	inline void Delegate<Args...>::addCallback(void* instance, void(INST::* function)(Args...))
	{
		INST* inst = static_cast<INST*>(instance);
		auto bindedFunc = [inst, function](Args... args) 
			{
				(inst->*function)(args...);
			};
		_callbackVector.push_back(bindedFunc);
		_callbackMap[instance].push_back(bindedFunc);
	}
}


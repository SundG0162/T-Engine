#pragma once
namespace TEngine
{
	class Domain;
	class Layer
	{
	public:
		Layer();
		virtual ~Layer();

		bool operator<(const Layer& other)
		{
			return _priority < other.getPriority();
		}
	public:
		virtual void initialize(Domain* domain) abstract;
		virtual void perform() abstract;
	public:
		void setPriority(int& priority) { _priority = priority; }
		const int& getPriority() const { return _priority; }
		const bool& isActive() const { return _isActive; }
	protected:
		int _priority;
		Domain* _domain;
		bool _isActive;
	};
}
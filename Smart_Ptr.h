#pragma once

template<typename AnyT>
class Smrt_Ptr {
public:
	explicit Smrt_Ptr(AnyT* ptr);
	~Smrt_Ptr();
	AnyT& operator*() const noexcept;
	AnyT* operator->() const noexcept;
private:
	AnyT* m_ptr;
};

template<typename AnyT>
Smrt_Ptr<AnyT>::Smrt_Ptr(AnyT* ptr)
{
	m_ptr = ptr;
}

template<typename AnyT>
inline Smrt_Ptr<AnyT>::~Smrt_Ptr()
{
	delete[]m_ptr;
}

template<typename AnyT>
AnyT& Smrt_Ptr<AnyT>::operator*() const noexcept
{
	return *m_ptr;
}

template<typename AnyT>AnyT* Smrt_Ptr<AnyT>::operator->() const noexcept
{
	return m_ptr;
}

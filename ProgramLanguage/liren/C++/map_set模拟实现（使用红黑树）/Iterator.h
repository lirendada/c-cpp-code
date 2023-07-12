#pragma once
// ·´Ïòµü´úÆ÷--µü´úÆ÷ÊÊÅäÆ÷
template <class Iterator>
struct ReverseIterator
{
	typedef ReverseIterator<Iterator> Self;
	typedef typename Iterator::Ref Ref;
	typedef typename Iterator::Ptr Ptr;

	ReverseIterator(Iterator it)
		:_it(it)
	{}

	Ref operator*()
	{
		return *_it;
	}

	Ptr operator->()
	{
		return _it.operator->();
	}

	Self& operator++()
	{
		--_it;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		--_it;
		return tmp;
	}

	Self& operator--()
	{
		++_it;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(_it);
		++_it;
		return tmp;
	}

	bool operator!=(const Self& s) const
	{
		return _it != s._it;
	}

	bool operator==(const Self& s) const
	{
		return _it == s._it;
	}

	Iterator _it;
};
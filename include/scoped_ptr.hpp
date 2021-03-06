#include <iostream>

template <typename T>
class scoped_ptr{
private:
	T * ptr_;
public:
	scoped_ptr(T * ptr = nullptr){
		ptr_ = ptr;
	}
	~scoped_ptr(){
		if(ptr_){
			delete ptr_;
		}
	}
	void reset(T * ptr){
		if(ptr_){
			delete ptr_;
		}
		ptr_ = ptr;
	}
	T & operator *() const{
		return *ptr_;
	}
	T * operator ->() const{
		return ptr_;
	}
	T * get() const{
		return ptr_;
	}
	void swap(scoped_ptr & other){
		std::swap(ptr_, other.ptr_);
	}
	scoped_ptr & operator=(scoped_ptr const &) = delete;
	scoped_ptr(scoped_ptr const &) = delete;
};

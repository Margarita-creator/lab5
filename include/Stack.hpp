//Copyright by Margarita-creator

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <memory>
#include <utility>

template <typename T>
class Stack
{
 public:
  Stack(const Stack&) = delete;
  Stack& operator = (const Stack&) = delete;
  Stack(): ref(nullptr) {
  }
  void push(T&& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(ref),
                                                      std::move(value)));
    ref = std::move(mov);
    //len++;
  }
  void push(const T& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(ref), (value)));
    ref = std::move(mov);
  }
  T pop() {
    if (ref!= nullptr) {
      auto del = ref->val;
      ref = std::move(ref->last);
      return del;
    }
    throw std::runtime_error("Stack is empty");
  }
  const T& head() const {
    return ref->val;
  }
 private:
  struct StackObj{
    typedef  std::unique_ptr < StackObj> StackObjPtr;
    StackObjPtr last;
    T val;
    explicit StackObj(StackObjPtr ref = nullptr, T valu = T()) {
      val = valu;
      last = std::move(ref);
    }
  };
  std::unique_ptr<StackObj> ref;
};

#endif // INCLUDE_STACK_HPP_


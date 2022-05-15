//Copyright by Margarita-creator

#ifndef INCLUDE_STACKSECOND_HPP_
#define INCLUDE_STACKSECOND_HPP_

#include <utility>
#include <memory>


template <typename T>
class TheSecondStack {
 public:
  TheSecondStack(const TheSecondStack&) = delete;
  TheSecondStack& operator = (const TheSecondStack&) = delete;
  TheSecondStack(): ref(nullptr) {}
  ~TheSecondStack(){
    while (ref) {
      pop();
    }
  }
  template <typename ... Args>
  void push_emplace(Args&&... value) {
    ref = std::move(std::make_unique<StackObj>(
        StackObj(std::move(ref), std::move(T(std::forward<Args>(value)...)))));
  }
  void push(T&& value) {
    ref = std::move(std::make_unique<StackObj>(
        StackObj(std::move(ref), std::forward<T>(value))));
  }
  const T& head() const {
    return ref->val;
  }
  T pop() {
    if (ref!= nullptr) {
      T del = std::move(ref->val);
      ref = std::move(ref->last);
      return del;
    }
    throw std::runtime_error("Empty");
  }
 private:
  struct StackObj{
    std::unique_ptr<StackObj> last;
    T val;
    explicit StackObj(std::unique_ptr<StackObj> ref = nullptr, T&& valu = T()) {
      val = std::forward<T>(valu);
      last = std::move(ref);
    }
  };
  std::unique_ptr<StackObj> ref;
};

#endif  // INCLUDE_STACKSECOND_HPP_



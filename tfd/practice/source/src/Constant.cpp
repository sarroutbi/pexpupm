#include "Constant.hpp"

Constant::Constant(const float & value) : Term(value) {}

bool Constant::equal(const Term & term) const {
  return term.getValue() == value_;
}

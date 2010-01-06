#ifndef IGLOO_STRINGOFLENGTHCONSTRAINT_H_
#define IGLOO_STRINGOFLENGTHCONSTRAINT_H_

namespace igloo {

  class StringOfLengthConstraint : public Constraint<unsigned int>
  {
  public:
    explicit StringOfLengthConstraint(int expectation) : Constraint<unsigned int>(expectation) {}

    virtual bool Evaluate(std::string actual) const
    {
      return actual.size() == _expected;
    }

    void ToString(std::string& str) const
    {
       std::ostringstream stm;
       stm << "string of length " << _expected;
       str += stm.str();
    }
  };
}

#endif

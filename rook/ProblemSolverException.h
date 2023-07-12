#ifndef PROBLEMSOLVEREXCEPTION_H
#define PROBLEMSOLVEREXCEPTION_H

#include <stdexcept>

class ProblemSolverException : public std::runtime_error {
public:
    explicit ProblemSolverException(const std::string& message) : std::runtime_error(message) {}

    explicit ProblemSolverException(const char* message) : std::runtime_error(message) {}

    virtual ~ProblemSolverException() throw () {}

    const char* what() const throw () override {
        return std::runtime_error::what();
    }
};

#endif  // PROBLEMSOLVEREXCEPTION_H
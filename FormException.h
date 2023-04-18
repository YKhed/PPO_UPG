
#ifndef FORMEXCEPTION_H
#define FORMEXCEPTION_H
#include <stdexcept>
#include <QString>

class FormException : public std::runtime_error {
public:
    explicit FormException(const std::string &message)
        : std::runtime_error(message) {}
};
#endif // FORMEXCEPTION_H

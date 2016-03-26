#ifndef UTILS
#define UTILS

#endif // UTILS

#include <QString>
#include <sstream>

template<typename T> QString toQString(T & t)
{
    std::stringstream s;
    s << t;
    std::string s1;
    s1 = s.str();
    return QString(s1.c_str());
}

template<typename T> T fromQString(const QString & string)
{
    T ret;
    std::stringstream s;
    std::string s1 = string.toStdString();
    s << s1;
    s >> ret;
    return ret;
}

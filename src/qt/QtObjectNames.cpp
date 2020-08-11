#include "QtObjectNames.h"

namespace
{
    std::string SUBMIT_INPUT_NAME = "inputSubmit";
    std::string OUPUT_RECEIVER_NAME = "outputReceiver";
}

QString cppexplore::QtObjectNames::inputSubmitName()
{
    return QString::fromStdString(SUBMIT_INPUT_NAME);
}

QString cppexplore::QtObjectNames::outputReceiverName()
{
    return QString::fromStdString(OUPUT_RECEIVER_NAME);
}

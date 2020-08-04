#include "QtObjectNames.h"

using namespace cppexplore;

const std::string QtObjectNames::SUBMIT_INPUT_NAME = "inputSubmit";
const std::string QtObjectNames::OUPUT_RECEIVER_NAME = "outputReceiver";

QString QtObjectNames::inputSubmitName()
{
    return QString::fromStdString(SUBMIT_INPUT_NAME);
}

QString QtObjectNames::outputReceiverName()
{
    return QString::fromStdString(OUPUT_RECEIVER_NAME);
}

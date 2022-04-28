#include "FirstNRepeatingStream_v3.h"

FirstNRepeatingStream::FirstNRepeatingStream(int N) : repeatCount(N)
{
}

FirstNRepeatingStream::~FirstNRepeatingStream()
{
    repeatCount = 0;
    inputStreamMap.clear();
    correctInputList.clear();
}

std::optional<char> FirstNRepeatingStream::next(char c)
{
    if (inputStreamMap.count(c))
    {
        inputStreamMap[c]++;
    }
    else
    {
        inputStreamMap.insert(std::make_pair(c, 1));
        correctInputList.push_back(c);
    }

    if (inputStreamMap[c] > repeatCount)
    {
        //remove from list
        correctInputList.remove(c);
    }
    if (correctInputList.empty())
    {
        return std::nullopt;
    }

    return correctInputList.front();
}

void testCharacterInputStream(std::string a_inputStream, int a_repeatCount)
{
    std::cout << "\ntestCharacterInputStream with N=" << a_repeatCount << std::endl;
	FirstNRepeatingStream tmpObj(a_repeatCount);

	for (int i = 0; i < a_inputStream.size(); ++i)
	{
		if (auto tmp = tmpObj.next(a_inputStream[i]); tmp)
			std::cout << a_inputStream[i] << "   -->   " << *tmp << std::endl;
		else
			std::cout << a_inputStream[i] << "   -->   NULL" << std::endl;
	}
}
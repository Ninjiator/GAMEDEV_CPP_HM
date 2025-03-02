#pragma once

class LengthComparator 
{
public:
	LengthComparator() = default;
	bool operator()(const std::string& str1, const std::string& str2)
	{
		return str1.length() < str2.length();
	}
	
private:
	
};
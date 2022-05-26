#include <iostream>
#include <vector>
// �������� �����������. 
// �������� �� ���� ����������� (������ ���� RGB), 
// ��������� ��������� � ����������� ������������ ����� �������� 
// (�������� ������������� �� ������ ��������������), 
// �� ����� ������ ������ ���� RGB ����� ���������� ��������. 
// ����������� ������-�������.

class Picture
{
public:
    int a;
};

class BaseFilter
{

public:
    virtual int Transform(Picture& picture) = 0;
    virtual int Process(Picture& in, Picture& out) = 0;

};

class BlackWhiteFilter :public BaseFilter
{
public:
    virtual int Transform(Picture& picture)
    {
        /*for (auto& it : picture)
        {
            it.R = it.G = it.B = (it.R + it.G + it.B) / 3;
        }*/
    }
    virtual int Process(Picture& in, Picture& out)
    {

    };
};



class Editor
{
public:

    void ApplyFilter(BaseFilter& a_filter, Picture& picture)
    {
        a_filter.Transform(picture);
    }

    void ApplyManyFilters(std::vector<BaseFilter*> &a_vec, Picture &picture)
    {
        for (auto& it : a_vec)
        {
            it->Transform(picture);
        }
    }


};

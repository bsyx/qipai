#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "set_table.h"

using namespace std;

SetTable::SetTable()
{
}

SetTable::~SetTable()
{
}

bool SetTable::check(int number)
{
    std::set<int>::iterator it = m_tbl.find(number);
    return it != m_tbl.end();
}

void SetTable::add(int key)
{
    m_tbl.insert(key);
}

void SetTable::dump(char* name)
{
    FILE *fp = fopen(name, "wb+");

    int num = m_tbl.size();

    fwrite(&num, 4, 1, fp);

    for(std::set<int>::iterator it=m_tbl.begin(); it!=m_tbl.end(); ++it)
    {
        int key = *it;
        fwrite(&key, 4, 1, fp);
    }

    fclose(fp);
}

void SetTable::load(char* name)
{
    FILE *fp = fopen(name, "rb");

	int key = 0;
	int num = 0;
	while (fscanf(fp, "%d\n", &key) != EOF)
	{
		num++;
		add(key);
	}

    printf("load %s %d key, set_size = %d\n", name, num, m_tbl.size());
    fclose(fp);
}

#pragma once
#include <iostream>
#include "Source.cpp"

DoubleList<char> line_transform(DoubleList<char> line, int &max) {
    int count = 0;
    int line_len = line.size();
    for (int i = 0; i < line_len; i++)
    {
        if (line[i] == ' ')
        {
            count++;
            if (count == 5)
            {
                for (int j = count; j > 0; j--)
                    line[i - (j - 1)] = '_';
            }
            else if (count > 5)
            {
                line[i] = '_';
            }
        }
        else
        {
            if (count < 5)
            {
                for (int j = count; j > 0; j--)
                {
                    line[i - j] = 0;
                }
            }
            if (count > max)
                max = count;
            count = 0;
        }
    }
    if (count > max)
        max = count;
    if (count < 5)
    {
        line.remove(' ');
    }
    else
    {
        for (int i = 0; i < line_len; i++)
        {
            if (line[i] == ' ')
                line[i] = '_';
        }
    }
    return line;
}

OneList<char> line_transform(OneList<char> line, int &max) {
    int count = 0;
    int line_len = line.size();
    for (int i = 0; i < line_len; i++)
    {
        if (line[i] == ' ')
        {
            count++;
            if (count == 5)
            {
                for (int j = count; j > 0; j--)
                    line[i - (j - 1)] = '_';
            }
            else if (count > 5)
            {
                line[i] = '_';
            }
        }
        else
        {
			if (count < 5)
			{
				for (int j = count; j > 0; j--)
				{
					line[i - j] = 0;
				}
			}
			if (count > max)
				max = count;
			count = 0;
        }
    }
    if (count > max)
	max = count;
    if (count < 5)
    {
        line.remove(' ');
    }
    else
    {
        for (int i = 0; i < line_len; i++)
        {
            if (line[i] == ' ')
                line[i] = '_';
        }
    }
    return line;
}
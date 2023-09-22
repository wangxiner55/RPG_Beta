#pragma once
#include <iostream>


template<typename Func, typename... Args>
void ExecCal(Func func, Args... args)
{
	(func(args), ...)
}

#include "RE/RTTI.h"

#include <cassert>

#include "SKSE/Logger.h"


namespace RE
{
	namespace RTTI
	{
		void DumpTypeName(void* a_obj)
		{
			assert(a_obj);
			auto vtbl = *reinterpret_cast<std::uintptr_t**>(a_obj) - 1;
			auto col = *reinterpret_cast<CompleteObjectLocator**>(vtbl);
			assert(col);

#ifdef DBHLPAPI
			char buf[0x1000];
			UnDecorateSymbolName(col->typeDescriptor->name + 1, buf, sizeof(buf), UNDNAME_COMPLETE);
			auto name = buf;
#else
			auto name = col->typeDescriptor->name;
#endif

			_DMESSAGE("0x%08X: %s", a_obj, name);
		}
	}
}

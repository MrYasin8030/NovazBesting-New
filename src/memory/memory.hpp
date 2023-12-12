#pragma once
#include "../lazy.hpp"

#include "../utils/xorstr.hpp"

#include "../utils/pattern/pattern.hpp"

namespace mem {
	uintptr_t game_assembly_base = 0;
	uintptr_t unity_player_base = 0;
	template<typename t>
	t read(uintptr_t addr) {
		if (addr < 0xffffff)
			return t();
		if (addr > 0x7fffffff0000)
			return t();

		return *reinterpret_cast<t*>(addr);
	}

	template<typename t>
	bool write(uintptr_t addr, t buffer) {
		*reinterpret_cast<t*>(addr) = buffer;
		return true;
	}

	uintptr_t hook_virtual_function(const char* classname, const char* function_to_hook, void* target, const char* name_space);
}

#define safe_read(Addr, Type) mem::read<Type>((DWORD64)Addr)
#define safe_write(Addr, Data, Type) mem::write<Type>((DWORD64)Addr, Data);

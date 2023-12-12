#include <Windows.h>
#include <intrin.h>
#include <cstdint>
#include <dxgi.h>
#include <time.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include "offsets.h"
#include "rust/rust.hpp"
#include "memory/memory.hpp"

#include "memory/il2cpp.hpp"
#include "utils/no_crt.hpp"
#include "utils/xorstr.hpp"
#include "utils/pattern/pattern.hpp"
#include "gui/render.hpp"
#include "MrYasingui.h"
#include "rust/unity.hpp"
#include "rust/features/player_esp.hpp"
#include "hooks.hpp"
 
bool has_initialized = false;



bool DllMain(uintptr_t hmodule)
{
	//if (!Check())
	//	return 0;

	if (!has_initialized) {

		mem::game_assembly_base = LI_MODULE_SAFE_(_("GameAssembly.dll"));
		mem::unity_player_base = LI_MODULE_SAFE_(_("UnityPlayer.dll"));


		il2cpp::init(); // yes
		unity::init_unity(); // yes
		gui::init_gui(); // yes
		hooks::init_hooks(); // yes
		init_bp(); // yes


		has_initialized = true; // yes
	}

	il2cpp::hook(&hooks::hk_performance_ui_update, _("Update"), _("PerformanceUI"), _("Facepunch"), 0); // yes
	il2cpp::hook(&apex_menu, _("OnGUI"), _("DevControls"), _(""), 0); // yes
	mem::hook_virtual_function(_("BasePlayer"), _("ClientInput"), &hooks::hk_baseplayer_ClientInput); // 
	 
	//mem::hook_virtual_function(_("BaseProjectile"), _("LaunchProjectile"), &hooks::hk_LaunchProjectile); // 

	return true;
}

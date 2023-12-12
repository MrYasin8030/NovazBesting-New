#pragma once
#include "../rust/unity.hpp"
#include "../rust/features/player_esp.hpp"
#include "../vars.hpp"
#include <windows.h>
#include <string>

#define PI 3.14159265358979323846

class CBounds {
public:
	Vector center;
	Vector extents;
};

inline float NormalizeAngle(float angle) {
	while (angle > 360.0f) {
		angle -= 360.0f;
	}
	while (angle < 0.0f) {
		angle += 360.0f;
	}
	return angle;
}

inline Vector NormalizeAngless(Vector angles) {
	angles.x = NormalizeAngle(angles.x);
	angles.y = NormalizeAngle(angles.y);
	angles.z = NormalizeAngle(angles.z);
	return angles;
}

inline Vector EulerAngles(vector4 q1) {
	float num = q1.w * q1.w;
	float num2 = q1.x * q1.x;
	float num3 = q1.y * q1.y;
	float num4 = q1.z * q1.z;
	float num5 = num2 + num3 + num4 + num;
	float num6 = q1.x * q1.w - q1.y * q1.z;
	Vector vector;
	if (num6 > 0.4995f * num5) {
		vector.y = 2.0f * m_atan2(q1.y, q1.x);
		vector.x = 1.57079637f;
		vector.z = 0.0f;
		return NormalizeAngless(vector * 57.2958f);
	}
	if (num6 < -0.4995f * num5) {
		vector.y = -2.0f * m_atan2(q1.y, q1.x);
		vector.x = -1.57079637f;
		vector.z = 0.0f;
		return NormalizeAngless(vector * 57.2958f);
	}
	vector4 quaternion = vector4(q1.w, q1.z, q1.x, q1.y);
	vector.y = m_atan2(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
	vector.x = m_asin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
	vector.z = m_atan2(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
	return NormalizeAngless(vector * 57.2958f);
}

#define rgba(r,g,b,a) Color(r / 255, g / 255, b / 255, a)
namespace gui {
	float menu_alpha;
	bool main_menu_open = false;

	namespace methods {
		static auto dont_destroy_on_load = reinterpret_cast<void(*)(uintptr_t target)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("DontDestroyOnLoad"), 0, _(""), _("UnityEngine"))));

		static auto create_with_shader_fn = reinterpret_cast<void(*)(uintptr_t self, uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("CreateWithShader"), 0, _(""), _("UnityEngine"))));

		static auto create = reinterpret_cast<void(*)(uintptr_t self, rust::classes::string shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_CreateGameObject"), 0, _(""), _("UnityEngine"))));

		static auto AddComponent = reinterpret_cast<void(*)(uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("AddComponent"), 0, _(""), _("UnityEngine"))));


		static auto get_whiteTexture = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

		static auto get_skin = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));

		static auto set_fontSize = reinterpret_cast<void(*)(uintptr_t label, int size)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), -1, _(""), _("UnityEngine"))));

		static auto set_color = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_color"), -1, _(""), _("UnityEngine"))));
		
		static auto Label = reinterpret_cast<void(*)(rust::classes::Rect position, uintptr_t content, uintptr_t style)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

		static auto _Label = reinterpret_cast<void(*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));
		
		static auto ptr_Label = reinterpret_cast<void(*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		static auto set_alignment = reinterpret_cast<void(*)(uintptr_t label, uintptr_t value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), -1, _(""), _("UnityEngine"))));

		static auto get_current = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));

		static auto gui_content_temp = reinterpret_cast<uintptr_t(*)(rust::classes::string*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		static auto gui_content_temp_ptr = reinterpret_cast<uintptr_t(*)(uintptr_t*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		static auto set_skin = reinterpret_cast<void(*)(uintptr_t skin)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_skin"), 0, _(""), _("UnityEngine"))));

		static auto get_type = reinterpret_cast<rust::classes::EventType(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));

		static auto LoadAllAssets = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAllAssets"), 1, _("type"), _("UnityEngine"), 1)));

		static auto LoadFromFile = reinterpret_cast<uintptr_t(*)(rust::classes::string path)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));

		static auto DrawTexture = reinterpret_cast<void (*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));

		static auto Box = reinterpret_cast<void (*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Box"), 2, _("text"), _("UnityEngine"), 2)));

		static auto DrawLine = reinterpret_cast<void (*)(Vector, Vector, Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Debug"), _("DrawLine"), 3, _(""), _("UnityEngine"))));

		static auto set_gizmos_color = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Gizmos"), _("set_color"), -1, _(""), _("UnityEngine"))));

		static auto HorizontalSlider = reinterpret_cast<float(*)(rust::classes::Rect position, float value, float leftValue, float rightValue)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("HorizontalSlider"), 4, _(""), _("UnityEngine"))));

		static auto PushMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PushMatrix"), 0, _(""), _("UnityEngine"))));

		static auto SetPass = reinterpret_cast<bool(*)(uintptr_t xui, int pass)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetPass"), 0, _(""), _("UnityEngine"))));

		static auto Begin = reinterpret_cast<void(*)(int mode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Begin"), 0, _(""), _("UnityEngine"))));

		static auto Color2 = reinterpret_cast<void(*)(Color color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Color"), 0, _(""), _("UnityEngine"))));

		static auto Vertex = reinterpret_cast<void(*)(Vector v)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex"), 0, _(""), _("UnityEngine"))));

		static auto Vertex2 = reinterpret_cast<void(*)(float, float, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex3"), 0, _(""), _("UnityEngine"))));

		static auto End = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("End"), 0, _(""), _("UnityEngine"))));

		static auto PopMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PopMatrix"), 0, _(""), _("UnityEngine"))));

		static auto Line = reinterpret_cast<void (*)(Vector, Vector, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 1, _(""), _("UnityEngine"))));

		static auto add_component = reinterpret_cast<void(*)(uintptr_t self, uintptr_t componentType)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_AddComponentWithType"), 0, _(""), _("UnityEngine"))));

		//static auto bobing = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("bobing"), 0, _(""), _(""))));


		static auto get_activemodel = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("get_ActiveModel"), 0, _(""), _(""))));
	}

	uintptr_t white_texture;

	void init_gui() {
		methods::PopMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PopMatrix"), 0, _(""), _("UnityEngine"))));

		methods::End = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("End"), 0, _(""), _("UnityEngine"))));

		methods::Vertex = reinterpret_cast<void(*)(Vector v)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex"), 0, _(""), _("UnityEngine"))));

		methods::Vertex2 = reinterpret_cast<void(*)(float, float, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex3"), 0, _(""), _("UnityEngine"))));


		methods::Color2 = reinterpret_cast<void(*)(Color color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Color"), 0, _(""), _("UnityEngine"))));

		methods::Begin = reinterpret_cast<void(*)(int mode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Begin"), 0, _(""), _("UnityEngine"))));

		methods::SetPass = reinterpret_cast<bool(*)(uintptr_t xui, int pass)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetPass"), 0, _(""), _("UnityEngine"))));

		methods::PushMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PushMatrix"), 0, _(""), _("UnityEngine"))));

		methods::dont_destroy_on_load = reinterpret_cast<void(*)(uintptr_t target)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("DontDestroyOnLoad"), 0, _(""), _("UnityEngine"))));
		//methods::bobing = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("bobing"), 0, _(""), _(""))));

		methods::create_with_shader_fn = reinterpret_cast<void(*)(uintptr_t self, uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("CreateWithShader"), 0, _(""), _("UnityEngine"))));

		methods::create = reinterpret_cast<void(*)(uintptr_t self, rust::classes::string shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_CreateGameObject"), 0, _(""), _("UnityEngine"))));

		methods::AddComponent = reinterpret_cast<void(*)(uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("AddComponent"), 0, _(""), _("UnityEngine"))));

		methods::ptr_Label = reinterpret_cast<void(*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		methods::gui_content_temp_ptr = reinterpret_cast<uintptr_t(*)(uintptr_t*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		methods::HorizontalSlider = reinterpret_cast<float(*)(rust::classes::Rect position, float value, float leftValue, float rightValue)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("HorizontalSlider"), 4, _(""), _("UnityEngine"))));

		methods::get_whiteTexture = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

		methods::get_skin = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));

		methods::set_fontSize = reinterpret_cast<void(*)(uintptr_t label, int size)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), -1, _(""), _("UnityEngine"))));

		methods::set_color = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_color"), -1, _(""), _("UnityEngine"))));

		methods::Label = reinterpret_cast<void(*)(rust::classes::Rect position, uintptr_t content, uintptr_t style)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

		methods::_Label = reinterpret_cast<void(*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		methods::set_alignment = reinterpret_cast<void(*)(uintptr_t label, uintptr_t value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), -1, _(""), _("UnityEngine"))));

		methods::get_current = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));

		methods::gui_content_temp = reinterpret_cast<uintptr_t(*)(rust::classes::string*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		methods::set_skin = reinterpret_cast<void(*)(uintptr_t skin)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_skin"), 0, _(""), _("UnityEngine"))));

		methods::get_type = reinterpret_cast<rust::classes::EventType(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));

		methods::LoadAllAssets = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAllAssets"), 1, _("type"), _("UnityEngine"), 1)));

		methods::LoadFromFile = reinterpret_cast<uintptr_t(*)(rust::classes::string path)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));

		methods::DrawTexture = reinterpret_cast<void (*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));

		methods::Box = reinterpret_cast<void (*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Box"), 2, _("text"), _("UnityEngine"), 2)));

		methods::DrawLine = reinterpret_cast<void (*)(Vector, Vector, Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Debug"), _("DrawLine"), 3, _(""), _("UnityEngine"))));

		methods::set_gizmos_color = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Gizmos"), _("set_color"), 1, _(""), _("UnityEngine"))));

		methods::Line = reinterpret_cast<void (*)(Vector, Vector, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));

		methods::add_component = reinterpret_cast<void(*)(uintptr_t self, uintptr_t componentType)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_AddComponentWithType"), 0, _(""), _("UnityEngine"))));

		methods::get_activemodel = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("get_ActiveModel"), 0, _(""), _(""))));

		white_texture = methods::get_whiteTexture();
	}

	uintptr_t label, skin;
	bool open;
	bool InsertPressed;

	float tick_time_when_called;

	void outline_box(vector2 pos, vector2 size, Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x + size.x, pos.y, 1, size.y + 1), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size.x, 1), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y + size.y, size.x, 1), white_texture);
	}

	void horizontal_line(vector2 pos, float size, Color clr)
	{
		methods::set_color(clr.GetUnityColor());

		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size, 1), white_texture);
	}

	void vertical_line(vector2 pos, float size, Color clr)
	{
		methods::set_color(clr.GetUnityColor());

		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, 1, size), white_texture);
	}

	void fill_box(rust::classes::Rect pos, Color clr)
	{
		methods::set_color(clr);
		methods::DrawTexture(pos, white_texture);
	}
	void fill_box2(rust::classes::Rect pos, Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(pos, white_texture);
	}
	void init() {
		if (label && skin)
			return;

		skin = methods::get_skin();
		label = mem::read<uintptr_t>(skin + 0x38);

		unity::bundle = unity::LoadFromFile(_(L"C:\\rust.assets"));
		
		unity::bundle3 = unity::LoadFromFile(_(L"C:\\circuit.bundle"));
		
		methods::set_alignment(label, 0);
		methods::set_fontSize(label, 10);
		methods::set_color(Color(1, 1, 1, 1));
	}
	void Text(float x, float y, float m_flWidth, float m_flHeight, rust::classes::string text, Color clr, bool centered = false, bool m_bOutlined = true, float size = 12) {

		uintptr_t content = methods::gui_content_temp(&text);

		//prepare style	

		if (centered)
			methods::set_alignment(label, 0x4);
		else
			methods::set_alignment(label, 0x0);

		float w = 0.0f;
		float h = 0.0f;

		if (!methods::set_alignment && m_flHeight == 0.0f && m_flWidth == 0.0f)
		{
			methods::set_fontSize(label, size);
			if (centered)
				x -= w / 2.0f;
		}
		else
		{
			w = m_flWidth;
			h = m_flHeight;
		}
		if (m_bOutlined)
		{
			methods::set_color(Color(0, 0, 0, 30));
			methods::_Label(rust::classes::Rect{ x - 1, y - 1, w, h }, text);
			methods::_Label(rust::classes::Rect{ x + 1, y + 1, w, h }, text);
			methods::_Label(rust::classes::Rect{ x - 1, y + 1, w, h }, text);
			methods::_Label(rust::classes::Rect{ x + 1, y - 1, w, h }, text);
		}

		methods::set_color(clr.GetUnityColor());
		methods::_Label(rust::classes::Rect{ x, y, w, h }, text);
	}
	void Label(rust::classes::Rect pos, rust::classes::string text, Color clr, bool centered = false, float size = 12) {
		methods::set_color(clr);

		uintptr_t content = methods::gui_content_temp(&text);

		methods::set_fontSize(label, size);          //prepare style	

		if (centered)
			methods::set_alignment(label, 0x4);
		else
			methods::set_alignment(label, 0x0);
		methods::_Label(pos, text);
	}

	void Label(rust::classes::Rect pos, uintptr_t text, Color clr, bool centered = false, float size = 12) {

		methods::set_color(clr);

		methods::set_fontSize(label, size);

		methods::ptr_Label(pos, text);
	}

	uintptr_t pizdec;
	void DrawFov(Color color, vector2 Center, float Radius) {
		pizdec = il2cpp::methods::object_new(il2cpp::init_class(_("Material"), _("UnityEngine")));
		methods::create_with_shader_fn(pizdec, Find(_(L"Hidden/Internal-Colored")));
		SetInt(pizdec, _(L"_SrcBlend"), 5);
		SetInt(pizdec, _(L"_DstBlend"), 10);
		SetInt(pizdec, _(L"_Cull"), 0);
		SetInt(pizdec, _(L"_ZWrite"), 0);
		gui::methods::dont_destroy_on_load(pizdec);

		gui::methods::PushMatrix();
		gui::methods::SetPass(pizdec, 0);
		gui::methods::Begin(1.5);
		gui::methods::Color2(color.GetUnityColor());
		for (float num = 0.f; num < 6.2831855f; num += 0.05f) {
			gui::methods::Vertex(Vector(m_cos(num) * Radius + Center.x, m_sin(num) * Radius + Center.y, 0));
			gui::methods::Vertex(Vector(m_cos(num + 0.05f) * Radius + Center.x, m_sin(num + 0.05f) * Radius + Center.y, 0));
		}
		gui::methods::End();
		gui::methods::PopMatrix();
	}

	void Draw_linex(Vector start, Vector end, Color color) {
		if (start.x > 0 && start.y > 0 && end.x > 0 && end.y > 0) {
			pizdec = il2cpp::methods::object_new(il2cpp::init_class(_("Material"), _("UnityEngine")));
			methods::create_with_shader_fn(pizdec, Find(_(L"Hidden/Internal-Colored")));
			SetInt(pizdec, _(L"_SrcBlend"), 5);
			SetInt(pizdec, _(L"_DstBlend"), 10);
			SetInt(pizdec, _(L"_Cull"), 0);
			SetInt(pizdec, _(L"_ZWrite"), 0);
			gui::methods::dont_destroy_on_load(pizdec);
			 
			gui::methods::PushMatrix();
			gui::methods::SetPass(pizdec, 0);
			gui::methods::Begin(1);
			gui::methods::Color2(color.GetUnityColor());

			gui::methods::Vertex(Vector(start.x, start.y, 0));
			gui::methods::Vertex(Vector(end.x, end.y, 0));

			gui::methods::End();
			gui::methods::PopMatrix();
		}
	}

	uintptr_t triangles_material;
 
	void OnKeyUp(rust::classes::KeyCode key) {
		if (key == rust::classes::KeyCode::Insert) {
			InsertPressed = false;
		}
	}

	bool m_bOpened;
	void OnKeyDown(rust::classes::KeyCode key) {
		if (!InsertPressed && key == rust::classes::KeyCode::Insert) {
			InsertPressed = true;
			open = !open;
			m_bOpened = !m_bOpened;
		}
	}

	int active_tab = 0;
	vector2 tab_size;
	int g_iCurrentTab = 0;
	void DrawHorizontalLine(float x, float y, float m_flWidth, Color m_Color)
	{
		methods::set_color(m_Color.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(x, y, m_flWidth, 1.0f), white_texture);
	}

	void HorizontalLine(vector2 pos, float size, Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size, 2), white_texture);
	}

	void DrawverticalLine(float x, float y, float m_flWidth, Color clr)
	{
		methods::set_color(clr.GetUnityColor());

		methods::DrawTexture(rust::classes::Rect(x, y, 20, m_flWidth), white_texture);
	}

	void Draw3dBox(Vector mid, float angle, float height, bool isWS, Color box_col)
	{
		CBounds bounds = CBounds();
		if (isWS)
		{
			bounds.center = mid;
			bounds.extents = Vector(0.7f, 0.35f, 0.4f);
		}
		else {
			bounds.center = mid + Vector(0.0f, height, 0.0f);
			bounds.extents = Vector(0.4f, height + 0.05f, 0.4f);
		}
		//config.rotateangl
		float y = angle;//config.rotateangl;//math::euler_angles(rootBone.rotation()).y;//config.rotateangl;// 
		Vector center = bounds.center;
		Vector extents = bounds.extents;
		Vector frontTopLeft = Math::rotate_point(center, Vector(center.x - extents.x, center.y + extents.y, center.z - extents.z), y);
		Vector frontTopRight = Math::rotate_point(center, Vector(center.x + extents.x, center.y + extents.y, center.z - extents.z), y);
		Vector frontBottomLeft = Math::rotate_point(center, Vector(center.x - extents.x, center.y - extents.y, center.z - extents.z), y);
		Vector frontBottomRight = Math::rotate_point(center, Vector(center.x + extents.x, center.y - extents.y, center.z - extents.z), y);
		Vector backTopLeft = Math::rotate_point(center, Vector(center.x - extents.x, center.y + extents.y, center.z + extents.z), y);
		Vector backTopRight = Math::rotate_point(center, Vector(center.x + extents.x, center.y + extents.y, center.z + extents.z), y);
		Vector backBottomLeft = Math::rotate_point(center, Vector(center.x - extents.x, center.y - extents.y, center.z + extents.z), y);
		Vector backBottomRight = Math::rotate_point(center, Vector(center.x + extents.x, center.y - extents.y, center.z + extents.z), y);

		Vector frontTopLeft_2d, frontTopRight_2d, frontBottomLeft_2d, frontBottomRight_2d, backTopLeft_2d, backTopRight_2d, backBottomLeft_2d, backBottomRight_2d;
		if ((frontTopLeft_2d = unity::screen_transform(frontTopLeft)).x &&
			(frontTopRight_2d = unity::screen_transform(frontTopRight)).x &&
			(frontBottomLeft_2d = unity::screen_transform(frontBottomLeft)).x &&
			(frontBottomRight_2d = unity::screen_transform(frontBottomRight)).x &&
			(backTopLeft_2d = unity::screen_transform(backTopLeft)).x &&
			(backTopRight_2d = unity::screen_transform(backTopRight)).x &&
			(backBottomLeft_2d = unity::screen_transform(backBottomLeft)).x &&
			(backBottomRight_2d = unity::screen_transform(backBottomRight)).x) {

			gui::Draw_linex(frontTopLeft_2d, frontTopRight_2d, box_col);
			gui::Draw_linex(frontTopRight_2d, frontBottomRight_2d, box_col);
			gui::Draw_linex(frontBottomRight_2d, frontBottomLeft_2d, box_col);
			gui::Draw_linex(frontBottomLeft_2d, frontTopLeft_2d, box_col);

			gui::Draw_linex(backTopLeft_2d, backTopRight_2d, box_col);
			gui::Draw_linex(backTopRight_2d, backBottomRight_2d, box_col);
			gui::Draw_linex(backBottomRight_2d, backBottomLeft_2d, box_col);
			gui::Draw_linex(backBottomLeft_2d, backTopLeft_2d, box_col);

			gui::Draw_linex(frontTopLeft_2d, backTopLeft_2d, box_col);
			gui::Draw_linex(frontTopRight_2d, backTopRight_2d, box_col);
			gui::Draw_linex(frontBottomRight_2d, backBottomRight_2d, box_col);
			gui::Draw_linex(frontBottomLeft_2d, backBottomLeft_2d, box_col);
		}
	}

	enum TextAnchor
	{
		UpperLeft = 0,
		UpperCenter = 1,
		UpperRight = 2,
		MiddleLeft = 3,
		MiddleCenter = 4,
		MiddleRight = 5,
		LowerLeft = 6,
		LowerCenter = 7,
		LowerRight = 8
	};

	bool g_bMousePressed = false;
	void line(vector2 start, vector2 end, Color color) {
		pizdec = il2cpp::methods::object_new(il2cpp::init_class(_("Material"), _("UnityEngine")));
		methods::create_with_shader_fn(pizdec, Find(_(L"Hidden/Internal-Colored")));
		SetInt(pizdec, _(L"_SrcBlend"), 5);
		SetInt(pizdec, _(L"_DstBlend"), 10);
		SetInt(pizdec, _(L"_Cull"), 0);
		SetInt(pizdec, _(L"_ZWrite"), 0);
		gui::methods::dont_destroy_on_load(pizdec);

		gui::methods::PushMatrix();
		gui::methods::SetPass(pizdec, 0);
		gui::methods::Begin(1);
		gui::methods::Color2(color.GetUnityColor());

		gui::methods::Vertex(Vector(start.x, start.y, 0));
		gui::methods::Vertex(Vector(end.x, end.y, 0));

		gui::methods::End();
		gui::methods::PopMatrix();
	}

	void rect(float x, float y, float w, float h, Color clr)
	{
		gui::methods::Color2(clr.GetUnityColor());
		gui::methods::DrawTexture({ x, y, 1, h }, white_texture);
		gui::methods::DrawTexture({ x + w, y + 1, 1, h }, white_texture);
		gui::methods::DrawTexture({ x, y, w + 1, 1 }, white_texture);
		gui::methods::DrawTexture({ x, y + h, w, 1 }, white_texture);
	}

	void Rect2(vector2 pos, vector2 size, Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x + size.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size.x, 1), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y + size.y, size.x, 1), white_texture);
	}
 

	static bool wakeup{ false };
	static bool sex{ false };
	vector2 window_pos{ 50, 50 }, mouse_pos, next_item_pos;
	vector2 window_sizemain;
	vector2 old_mouse_pos;
	bool mouse_state, insert_state;
	rust::classes::EventType menu_event;
	bool old_mouse_state, old_insert_state;

	vector2 widget_mouse_pos, old_widget_mouse_pos;
	bool widget_state, old_widget_state;
	float color_picker_alpha;
	bool is_menu_open{ true };
	bool interacting;

	void FullRect(rust::classes::Rect pos, Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(pos, white_texture);
	}

	void RenderRadarBackground(float Pos_x, float Pos_Y, float Rad)
	{
		if (vars::Radar::Enable)
		{
			FullRect({ Pos_x , Pos_Y,200,200 }, { 0, 0, 0, 70 });
			line({ Pos_x + 100, Pos_Y }, { Pos_x + 100 ,Pos_Y + 200 }, { 0, 0, 0, 255 });
			line({ Pos_x, Pos_Y + 100 }, { Pos_x + 200, Pos_Y + 100 }, { 0, 0, 0, 255 });
		}
	}

	Color perc_col(float Num, float alpha = 1.0f)
	{
		float red, green, blue;
		if (Num < 0.5)
		{
			red = Num * 2.f * 255.f;
			green = 255.f;
			blue = 0.f;
		}
		else
		{
			red = 255.f;
			green = (2.f - 2.f * Num) * 255.f;
			blue = 0.f;
		}

		red -= 100;
		green -= 100;
		blue -= 100;
		return Color(red / 255, green / 255, blue / 255, alpha);
	}

	void Progbar(vector2 start, vector2 end, float a, float b)
	{
		if (a < 0) return;
		fill_box(rust::classes::Rect(start.x, start.y, end.x, end.y + 1), Color(0, 0, 0, 255));

		if ((a / b) > 1)
			a = b;

		fill_box(rust::classes::Rect(start.x + 1, start.y + 1, (end.x * (a / b)) - 1, end.y - 1), perc_col(a / b));
	}
}


float unity::get_fov(Vector Pos) {
	esp::matrix = unity::get_view_matrix();

	Vector ScreenPos = WorldToScreen(Pos);
	if (ScreenPos.is_empty())
		return 1000;
	return get_2d_dist(vector2(unity::get_width() / 2, unity::get_height() / 2), ScreenPos);
}

void ColorConvertHSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b)
{
	if (s == 0.0f)
	{
		// gray
		out_r = out_g = out_b = v;
		return;
	}

	h = my_fmod(h, 1.0f) / (60.0f / 360.0f);
	int   i = (int)h;
	float f = h - (float)i;
	float p = v * (1.0f - s);
	float q = v * (1.0f - s * f);
	float t = v * (1.0f - s * (1.0f - f));

	switch (i)
	{
	case 0: out_r = v; out_g = t; out_b = p; break;
	case 1: out_r = q; out_g = v; out_b = p; break;
	case 2: out_r = p; out_g = v; out_b = t; break;
	case 3: out_r = p; out_g = q; out_b = v; break;
	case 4: out_r = t; out_g = p; out_b = v; break;
	case 5: default: out_r = v; out_g = p; out_b = q; break;
	}
}

Color HSV(float h, float s, float v, float a = 1.0f) { float r, g, b; ColorConvertHSVtoRGB(h, s, v, r, g, b); return Color(r, g, b, a); }


void esp::dropped_items(vector2 w2s_position, wchar_t* label, Color color, wchar_t* name) {
	if (label) {
		gui::Text	(w2s_position.x, w2s_position.y + 2, 150, 20, label, color, false, true, 12);
	}
	else {
		gui::Text(w2s_position.x, w2s_position.y + 2, 150, 20, name, color, false, true, 12);
	}
}
void esp::draw_item(vector2 w2s_position, uintptr_t label, Color color) {

	if (label) {
		gui::Label(rust::classes::Rect{ w2s_position.x + 1, w2s_position.y + 3, 150, 20 }, label, Color(145, 185, 200, 120), false, 12);
		gui::Label(rust::classes::Rect{ w2s_position.x, w2s_position.y + 2, 150, 20 }, label, Color(115, 165, 200, 120), false, 12);
	}

}
 

void esp::miscvis(DWORD64 ObjectClass, char* buff, bool boolean, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, Color Col) {
	if (boolean && m_strstr(buff, substring)) {
		DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64);
		DWORD64 transform = safe_read(gameObject + 0x8, DWORD64);
		DWORD64 vector = safe_read(transform + 0x38, DWORD64);
		Vector game_Pos = safe_read(vector + 0x90, Vector);
		vector2 screen_Pos;
		if (esp::out_w2s(game_Pos, screen_Pos)) {
			if ((int)Calc3D_Dist(local_player->GetBoneByID(head), game_Pos) <= drawDistance) {
				gui::Text(screen_Pos.x - 40, screen_Pos.y, 150, 20, targettext, Col, true, 12);
				if (showDistance) {
					int distation = (int)Calc3D_Dist(local_player->GetBoneByID(head), game_Pos);
					 
					char m_szHealth[256];
					wchar_t m_wszHealth[256];
					itoass(static_cast<int>(distation), m_szHealth, 10);
					AnsiToUnicode(m_szHealth, m_wszHealth);
					gui::Text(screen_Pos.x - 40, screen_Pos.y + 10, 150, 20, m_wszHealth, Col, 12);

				}
			}
		}
	}
}

void esp::stash(DWORD64 ObjectClass, DWORD64 Object, char* buff) {
	typedef bool(__stdcall* IsHidden)(BaseEntity*);
	if (vars::visuals::stash) {
		if (m_strstr(buff, _("small_stash_deployed.prefab"))) {
			BaseEntity* stash = (BaseEntity*)Object;
			if (stash) {
				DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64);
				DWORD64 transform = safe_read(gameObject + 0x8, DWORD64);
				DWORD64 vector = safe_read(transform + 0x38, DWORD64);
				Vector game_Pos = safe_read(vector + 0x90, Vector);
				vector2 screen_Pos;
				if (esp::out_w2s(game_Pos, screen_Pos)) {
					if ((int)Calc3D_Dist(local_player->GetBoneByID(head), game_Pos) <= vars::visuals::distance_resource) {
						if (((IsHidden)(mem::game_assembly_base + CO::IsHidden))(stash)) {
							gui::Text(screen_Pos.x - 40, screen_Pos.y, 150, 20, _(L"Stash [Hidden]"), Color(255, 150, 0, 255), true, 12);
							if (vars::visuals::showDistance) {
								int distation = (int)Calc3D_Dist(local_player->GetBoneByID(head), game_Pos);
								char m_szHealth[256];
								wchar_t m_wszHealth[256];
								itoass(static_cast<int>(distation), m_szHealth, 10);
								AnsiToUnicode(m_szHealth, m_wszHealth);
								gui::Text(screen_Pos.x - 40, screen_Pos.y + 10, 150, 20, m_wszHealth, Color(255, 150, 0, 255), 12);
							}
						 
						}
						else {
							gui::Text(screen_Pos.x - 40, screen_Pos.y, 150, 20, _(L"Stash [Opened]"), Color(255, 255, 0, 255), true, 12);
							if (vars::visuals::showDistance) {
								int distation = (int)Calc3D_Dist(local_player->GetBoneByID(head), game_Pos);
								char m_szHealth[256];
								wchar_t m_wszHealth[256];
								itoass(static_cast<int>(distation), m_szHealth, 10);
								AnsiToUnicode(m_szHealth, m_wszHealth);
								gui::Text(screen_Pos.x - 40, screen_Pos.y + 10, 150, 20,  m_wszHealth, Color(255, 255, 0, 255), 12);
							}
							 
						}
					}
				}
			}
		}
	}
}
void esp::HandChams(BasePlayer* player) {
	static float r = 1.00f, g = 0.00f, b = 1.00f;
	static int cases = 0;
	switch (cases) {
	case 0: { r -= 0.004f; if (r <= 0) cases += 1; break; }
	case 1: { g += 0.004f; b -= 0.004f; if (g >= 1) cases += 1; break; }
	case 2: { r += 0.004f; if (r >= 1) cases += 1; break; }
	case 3: { b += 0.004f; g -= 0.004f; if (b >= 1) cases = 0; break; }
	default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
	}
	if (vars::visuals::hand_chams) {
		if (unity::bundle || unity::bundle2 )
		{
			
			
			Material* shader = 0;
			auto model = gui::methods::get_activemodel();
			auto renderers = ((networkable*)model)->GetComponentsInChildren(unity::GetType(_("UnityEngine"), _("Renderer")));
			if (renderers)
			{
				auto sz = *reinterpret_cast<int*>(renderers + 0x18);

				for (int i = 0; i < sz; i++) {
					auto renderer = *reinterpret_cast<Renderer**>(renderers + 0x20 + i * 0x8);

					if (!renderer) continue;
					Material* material = renderer->GetMaterial();
					if (!material) continue;

					 
					if (vars::visuals::shader4) {
						
						Shader* shade2r = (Shader*)unity::LoadAsset(unity::bundle3, _(L"nebnel"), unity::GetType(_("UnityEngine"), _("Shader")));

						material->SetShader(shade2r);
						material->SetColor((L"_Color"), col(0.7, 2.7f, 2.8f, 0.9f));
					}
					if (vars::visuals::shader3) {
						
						Shader* shade1r = (Shader*)unity::LoadAsset(unity::bundle, _(L"WireframeTransparent"), unity::GetType(_("UnityEngine"), _("Shader")));

						material->SetShader(shade1r);
						material->SetColor((L"_Color"), col(1.0, 0.6f, 2.3f, 3.f));
					}
					
				}
			}
		}
	}
}

void esp::RadarPlayer(BasePlayer* player)
{
	if (local_player)
	{
		if (vars::Radar::Enable)
		{
			if (vars::Radar::Enable || vars::visuals::sleeper_esp)
			{
				if (!player->IsDead() && player->GetHealth() >= 0.2f)
				{
					const Vector LocalPos = local_player->get_bone_transform(48)->get_bone_position();
					const Vector PlayerPos = player->get_bone_transform(48)->get_bone_position();
					const float Distance = Distance3D(LocalPos, PlayerPos);
					const float y = LocalPos.x - PlayerPos.x;
					const float x = LocalPos.z - PlayerPos.z;
					Vector eulerAngles = Math::EulerAngles(local_player->Radar_eyes()->get_rotation());
					const float num = m_atan2(y, x) * 57.29578f - 270.f - eulerAngles.y;
					float PointPos_X = Distance * m_cos(num * 0.0174532924f);
					float PointPos_Y = Distance * m_sin(num * 0.0174532924f);
					PointPos_X = PointPos_X * (vars::Radar::Radar_Size / vars::Radar::Radar_Range) / 2.f;
					PointPos_Y = PointPos_Y * (vars::Radar::Radar_Size / vars::Radar::Radar_Range) / 2.f;
					 bool is_teammate = player->is_teammate(local_player);
					if (!player->HasFlags(16) && !player->HasFlags(64) && vars::Radar::Enable)
					{
						if (Distance <= vars::Radar::Radar_Range)
						{
							gui::FullRect({ vars::Radar::Pos_X + vars::Radar::Radar_Size / 2.f + PointPos_X - 3.f, vars::Radar::Pos_Y + vars::Radar::Radar_Size / 2.f + PointPos_Y - 3.f, 5, 5 }, { 118,124,184,255 });
						}
					}
					else if (player->HasFlags(16) && vars::visuals::sleeper_esp)
					{
						if (Distance <= vars::Radar::Radar_Range)
						{
							gui::FullRect({ vars::Radar::Pos_X + vars::Radar::Radar_Size / 2.f + PointPos_X - 3.f, vars::Radar::Pos_Y + vars::Radar::Radar_Size / 2.f + PointPos_Y - 3.f, 5, 5 }, { 118,124,184,255 });
						}
					}
					else if (player->HasFlags(64) && vars::visuals::woundedflag)
					{
						if (Distance <= vars::Radar::Radar_Range)
						{
							gui::FullRect({ vars::Radar::Pos_X + vars::Radar::Radar_Size / 2.f + PointPos_X - 3.f, vars::Radar::Pos_Y + vars::Radar::Radar_Size / 2.f + PointPos_Y - 3.f, 5, 5 }, { 118,124,184,255 });
						}
					}
				}
			}
		}
	}
}

 
void esp::draw_player(BasePlayer* player)
{
	if (!local_player)
		return;
	//   esp colors
	auto safezone_color = Color{ 255,255, 255, 1.0 };
	const Color visible_color = Color(0, 255, 255, 255); //green
	const Color invisible_color = Color(255, 0, 255, 255); //red
	const Color teammate_color = Color(155, 219, 59, 255); //blue
	const Color BoxFillColor = Color(0.33, 0.33, 0.33, 0.5); //gray
	const Color Wounded = Color(255, 0, 0, 255);
	bounds_t bounds;

	struct bone_t {
		Vector screen;
		int8_t     index;
		bool       on_screen;
		Vector world_position;
		bool visible;
	};

	std::array<bone_t, 20> bones = {
		bone_t{ Vector{}, 17, false, Vector{}, false }, bone_t{ Vector{}, 18, false, Vector{}, false },
		bone_t{ Vector{}, 15, false, Vector{}, false }, bone_t{ Vector{}, 14, false, Vector{}, false },
		bone_t{ Vector{}, 1, false, Vector{}, false },  bone_t{ Vector{}, 2, false, Vector{}, false },
		bone_t{ Vector{}, 3, false, Vector{}, false },  bone_t{ Vector{}, 6, false, Vector{}, false },
		bone_t{ Vector{}, 5, false, Vector{}, false },  bone_t{ Vector{}, 21, false, Vector{}, false },
		bone_t{ Vector{}, 23, false, Vector{}, false }, bone_t{ Vector{}, 48, false, Vector{}, false },
		bone_t{ Vector{}, 24, false, Vector{}, false }, bone_t{ Vector{}, 25, false, Vector{}, false },
		bone_t{ Vector{}, 26, false, Vector{}, false }, bone_t{ Vector{}, 27, false, Vector{}, false },
		bone_t{ Vector{}, 55, false, Vector{}, false }, bone_t{ Vector{}, 56, false, Vector{}, false },
		bone_t{ Vector{}, 57, false, Vector{}, false }, bone_t{ Vector{}, 76, false, Vector{}, false }
	};

	bool is_visible = false;

	 bool is_teammate = player->is_teammate(local_player);

	auto camera_position = unity::get_camera_pos();

	const auto get_bounds = [&](bounds_t& out, float expand = 0) -> bool {
		bounds = { FLT_MAX, FLT_MIN, FLT_MAX, FLT_MIN };

		for (auto& [bone_screen, bone_idx, on_screen, world_position, visible] : bones) {

			auto transform = player->get_bone_transform(bone_idx);

			world_position = transform->get_bone_position();

			if (bone_idx == 48) // lol
				world_position.y += 0.2f;

			bone_screen = WorldToScreen(world_position);
			if (bone_screen.x < bounds.left)
				bounds.left = bone_screen.x;
			if (bone_screen.x > bounds.right)
				bounds.right = bone_screen.x;
			if (bone_screen.y < bounds.top)
				bounds.top = bone_screen.y;
			if (bone_screen.y > bounds.bottom)
				bounds.bottom = bone_screen.y;
			on_screen = true;
		}

		if (bounds.left == FLT_MAX)
			return false;
		if (bounds.right == FLT_MIN)
			return false;
		if (bounds.top == FLT_MAX)
			return false;
		if (bounds.bottom == FLT_MIN)
			return false;

		bounds.left -= expand;
		bounds.right += expand;
		bounds.top -= expand;
		bounds.bottom += expand;

		out = bounds;

		return true;
	};

	if (get_bounds(bounds, 4)) {

		if (!is_visible)
			is_visible = player->is_visible(camera_position, bones[16].world_position);

		Color clr = !is_teammate ? (is_visible ? visible_color : invisible_color) : teammate_color;
		if (HasPlayerFlag(player, rust::classes::PlayerFlags::SafeZone))
			clr = safezone_color;

		if (HasPlayerFlag(player, rust::classes::PlayerFlags::Wounded))
			clr = Wounded;

		float box_width = bounds.right - bounds.left;
		float box_height = bounds.bottom - bounds.top;

		wchar_t* name = player->get_player_name();
		auto player_weapon = player->get_active_weapon();

		if (vars::visuals::boxesp) {
			if (vars::visuals::fill_box && vars::visuals::boxesp)
			{
				gui::fill_box2(rust::classes::Rect(bounds.left, bounds.top, box_width, box_height), Color(0, 0, 0, 135));
			}

			if (vars::visuals::full_box && vars::visuals::boxesp) {
				//full box
				gui::outline_box(vector2{ bounds.left - 1, bounds.top - 1 }, vector2{ box_width + 2, box_height + 2 }, Color(0, 0, 0, 120));
				gui::outline_box(vector2{ bounds.left, bounds.top }, vector2{ box_width, box_height }, clr);
			}

			if (vars::visuals::corner_box && vars::visuals::boxesp) {
				//corner box
				float X = bounds.left, Y = bounds.top, W = bounds.right - bounds.left, H = bounds.bottom - bounds.top;
				float lineW = (W / 5);
				float lineH = (H / 6);
				float lineT = 1;

				gui::line({ X, Y, }, { X, Y + lineH }, clr);
				gui::line({ X, Y }, { X + lineW, Y }, clr);
				gui::line({ X + W - lineW, Y }, { X + W, Y }, clr);
				gui::line({ X + W, Y }, { X + W, Y + lineH }, clr);
				gui::line({ X, Y + H - lineH }, { X, Y + H }, clr);
				gui::line({ X, Y + H }, { X + lineW, Y + H }, clr);
				gui::line({ X + W - lineW, Y + H }, { X + W, Y + H }, clr);
				gui::line({ X + W, Y + H - lineH }, { X + W, Y + H }, clr);
			}
		}

		const auto cur_health = player->get_health();
		const auto max_health = (100);
		const auto health_pc = min(cur_health / max_health, 1);
		const auto health_color =
			HSV((health_pc * .25f), 1, .875f * 1);

		const auto height = (bounds.bottom - bounds.top) * health_pc;
		int curpos = 0;
		//if (vars::visuals::healthbar) {
	/*	if (vars::visuals::sidehealth) {
			gui::fill_box2(rust::classes::Rect(bounds.left - 5, bounds.top, 4, box_height), Color(0, 0, 0, 255));
			gui::fill_box2(rust::classes::Rect(bounds.left - 4, bounds.top + box_height - height + 1, 2, height), Color(0, 255, 0, 255));
		}*/

			if (vars::visuals::sidehealth) {
				gui::fill_box2(rust::classes::Rect(bounds.left, bounds.bottom + 4, box_width + 1, 6), Color(0, 0, 0, 255));
				if ((int)player->get_health() <= 33) {
					gui::fill_box2(rust::classes::Rect(bounds.left + 2, bounds.bottom + 6, ((box_width / max_health)* cur_health) - 2, 2), Color(255, 0, 0, 255));
				}
				if ((int)player->get_health() >= 34 && (int)player->get_health() <= 66) {
					gui::fill_box2(rust::classes::Rect(bounds.left + 2, bounds.bottom + 6, ((box_width / max_health)* cur_health) - 2, 2), Color(255, 255, 0, 255));
				}
				if ((int)player->get_health() >= 67) {
					gui::fill_box2(rust::classes::Rect(bounds.left + 2, bounds.bottom + 6, ((box_width / max_health)* cur_health) - 2, 2), Color(0, 255, 0, 255));
				}
			}
		

		if (vars::visuals::dbox) {//{
			float angel = Math::EulerAngles(player->Radar_eyes()->get_rotation()).y;
			Vector midpoint;
			bool isw = 0;
			if (player->HasFlags(64) || player->HasFlags(16))  midpoint = player->get_bone_transform(1)->get_bone_position(), isw = 1;
			else midpoint = player->get_bone_transform(16)->get_bone_position().midPoint(player->get_bone_transform(4)->get_bone_position());

			gui::Draw3dBox((midpoint - Vector(0.0f, 0.1f, 0.0f)), angel, ((player->get_bone_transform(47)->get_bone_position().y) - midpoint.y) / 1.6, isw, clr);
		}

		if (player_weapon)
		{
			auto weapon_name = player_weapon->get_weapon_name();
			if (weapon_name)
			{
				// WEAPON NAME ESP
				if (vars::visuals::weaponesp) {
					auto half = (bounds.right - bounds.left) / 2;
					gui::Text(bounds.left - 80.f, bounds.bottom + 7, 80.f + half * 2 + 80.f, 20, weapon_name, clr, true, true, 9);
					curpos += 12;
				}
			}
		}

		if (vars::visuals::distance)
		{
			auto half = (bounds.right - bounds.left) / 2;
			auto transform = player->get_bone_transform(48);
			auto position = transform->get_bone_position();
			auto distance = local_player->get_bone_transform(48)->get_bone_position().Distance(position);
			char m_szHealth[256];
			wchar_t m_wszHealth[256];
			itoass(static_cast<int>(distance), m_szHealth, 10);
			AnsiToUnicode(m_szHealth, m_wszHealth);
			gui::Text(bounds.left - 80.f, bounds.top - 30.f, 80.f + half * 2 + 80.f, 20, m_wszHealth, clr, true, true, 9);
		}
		 
		 
		float xs2 = unity::get_width() / 2, ys2 = unity::get_height();
	
		if (name)
		{
		 
			
			if (vars::visuals::nameesp) {
				auto half = (bounds.right - bounds.left) / 2;
				auto transform = player->get_bone_transform(48);
				auto position = transform->get_bone_position();
				if (vars::visuals::woundedflag) {

					const wchar_t* woundedlol = L"*wounded*";

					if (HasPlayerFlag(player, rust::classes::PlayerFlags::Wounded)) {

						gui::Text(bounds.left - 80.f, bounds.top - 45.f, 80.f + half * 2 + 80.f, 20, woundedlol, clr, true, true, 9);
					}

				}
				gui::Text(bounds.left - 80.f, bounds.top - 18.f, 80.f + half * 2 + 80.f, 20, name, clr, true, true, 9);
				 
			}
		}

		if (vars::visuals::skeleton) {
			BoneList Bones[15] = {
				l_foot,
				l_knee,
				l_hip,
				r_foot,
				r_knee,
				r_hip,
				spine1,
				neck,
				head,
				l_upperarm,
				l_forearm,
				l_hand,
				r_upperarm,
				r_forearm,
				r_hand,
			}; vector2 BonesPos[15];
			for (int j = 0; j < 15; j++) {
				if (!esp::out_w2s(player->GetBoneByID(Bones[j]), BonesPos[j]))
					return;
			}
			for (int j = 0; j < 15; j += 3) {
				gui::line(vector2{ BonesPos[j].x, BonesPos[j].y }, vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, clr);
				gui::line(vector2{ BonesPos[j].x, BonesPos[j].y }, vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, clr);
				gui::line(vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, clr);
				gui::line(vector2{ BonesPos[j + 1].x, BonesPos[j + 1].y }, vector2{ BonesPos[j + 2].x, BonesPos[j + 2].y }, clr);
			}
			gui::line(vector2{ BonesPos[2].x, BonesPos[2].y }, vector2{ BonesPos[6].x, BonesPos[6].y }, clr);
			gui::line(vector2{ BonesPos[2].x, BonesPos[2].y }, vector2{ BonesPos[6].x, BonesPos[6].y }, clr);
			gui::line(vector2{ BonesPos[5].x, BonesPos[5].y }, vector2{ BonesPos[6].x, BonesPos[6].y }, clr);
			gui::line(vector2{ BonesPos[5].x, BonesPos[5].y }, vector2{ BonesPos[6].x, BonesPos[6].y }, clr);
			gui::line(vector2{ BonesPos[9].x, BonesPos[9].y }, vector2{ BonesPos[7].x, BonesPos[7].y }, clr);
			gui::line(vector2{ BonesPos[9].x, BonesPos[9].y }, vector2{ BonesPos[7].x, BonesPos[7].y }, clr);
			gui::line(vector2{ BonesPos[12].x, BonesPos[12].y }, vector2{ BonesPos[7].x, BonesPos[7].y }, clr);
			gui::line(vector2{ BonesPos[12].x, BonesPos[12].y }, vector2{ BonesPos[7].x, BonesPos[7].y }, clr);
		}
		//if (vars::visuals::npc_esp)
		//{
		//	if (!is_visible)
		//		is_visible = player->is_visible(camera_position, bones[16].world_position);

		//	Color clr = (is_visible ? visible_color : invisible_color);
		//	if (HasPlayerFlag(player, rust::classes::PlayerFlags::SafeZone))
		//		clr = safezone_color;

		//	if (HasPlayerFlag(player, rust::classes::PlayerFlags::Wounded))
		//		clr = Wounded;

		//	float box_width = bounds.right - bounds.left;
		//	float box_height = bounds.bottom - bounds.top;

		//	wchar_t* name = player->get_player_name();
		//	auto player_weapon = player->get_active_weapon();

		//	if (vars::visuals::npc_esp && player->GetSteamID() < 1000000000) {
		//		//full box
		//		gui::outline_box(vector2{ bounds.left - 1, bounds.top - 1 }, vector2{ box_width + 2, box_height + 2 }, Color(0, 0, 0, 120));
		//		gui::outline_box(vector2{ bounds.left, bounds.top }, vector2{ box_width, box_height }, clr);
		//		//full box
		//	}

		//	if (vars::visuals::npc_esp && player->GetSteamID() < 1000000000) {
		//		//corner box
		//		const auto cur_health = player->get_health();
		//		const auto max_health = (100);
		//		const auto health_pc = min(cur_health / max_health, 1);
		//		const auto health_color =
		//			HSV((health_pc * .25f), 1, .875f * 1);

		//		const auto     height = (bounds.bottom - bounds.top) * health_pc;
		//		int curpos = 0;
		//		if (vars::visuals::npc_esp) {
		//			gui::fill_box2(rust::classes::Rect(bounds.left - 5, bounds.top, 4, box_height), Color(0, 0, 0, 180));
		//			gui::fill_box2(rust::classes::Rect(bounds.left - 4, bounds.top + box_height - height + 1, 2, height), Color(169, 124, 252, 255));
		//		}

		//		if (player_weapon)
		//		{
		//			auto weapon_name = player_weapon->get_weapon_name();
		//			if (weapon_name)
		//			{
		//				// WEAPON NAME ESP
		//				if (vars::visuals::weaponesp && player->GetSteamID() < 1000000000) {
		//					auto half = (bounds.right - bounds.left) / 2;
		//					gui::Text(bounds.left - 80.f, bounds.bottom, 80.f + half * 2 + 80.f, 20, weapon_name, Color(255, 255, 255, 255), true, true, 9);
		//					curpos += 12;
		//				}
		//			}
		//		}

		//		if (vars::visuals::npc_esp && player->GetSteamID() < 1000000000)
		//		{
		//			auto half = (bounds.right - bounds.left) / 2;
		//			auto transform = player->get_bone_transform(48);
		//			auto position = transform->get_bone_position();
		//			auto distance = local_player->get_bone_transform(48)->get_bone_position().Distance(position);
		//			char m_szHealth[255];
		//			wchar_t m_wszHealth[255];
		//			itoass(static_cast<int>(distance), m_szHealth, 10);
		//			AnsiToUnicode(m_szHealth, m_wszHealth);
		//			gui::Text(bounds.left - 80.f, bounds.bottom + curpos, 80.f + half * 2 + 80.f, 20, m_wszHealth, Color(255, 255, 255, 255), true, true, 9);
		//			curpos += 12;
		//		}

		//		if (name)
		//		{
		//			if (player->GetSteamID() < 1000000000) {
		//				auto half = (bounds.right - bounds.left) / 2;
		//				auto transform = player->get_bone_transform(48);
		//				auto position = transform->get_bone_position();


		//				gui::Text(bounds.left - 80.f, bounds.top - 18.f, 80.f + half * 2 + 80.f, 20, name, Color(255, 255, 255, 255), true, true, 9);

		//			}
		//			// PLAYER NAME
		//		}
		//	}
		//}
	}

}
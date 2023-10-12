#pragma once

namespace vlgui {
	enum KFlag {
		K_EnableDocking,
		K_EnableResizable,
		K_ResizableBasedOnWindow,
		K_EnableClick,
	};
	
	/// <summary>
	/// Save as JSON and XML
	/// Near the same as GLADE GUI
	/// </summary>
	class Config {
	public:
		void Save();
		void Load();
	};

	//Manage how vlgui work
	class vlgui {
	public:
		//header
	public:
		void Begin();
		void End();
	public:
		void SetFont(int arg_fontPath);
		void PushFont(int arg_fontPath);
		void PopFont(int arg_fontPath);
	public:
		//--[ Canvas ]--

	public:
		//--[ Text ]--


	};

	//A frame that will use to draw graphics on
	class Canvas {
	private:
	public:		
		//Immediate Mode
		Canvas(int arg_nameId){ }
		//For HTML CSS
		Canvas(int arg_htmlPath){ }
	public:
		float x;
		float y;
		float z;
	public:
		float ScreenWidth;
		float ScreenHeight;		
	public:
		void Begin();
		void End();
	};

	class Text {
	public:
		float x;
		float y;
		float z;
	public:
		int Content;
	public:
		void SetPosition(float arg_x, float arg_y, float arg_z);
		void SetText(float arg_x, float arg_y, float arg_z);
		void SetTextSize(float arg_size);		
	};

	class Button {
	public:
		Button(int arg_text, int[] arg_flags);
	public:
		float x;
		float y;
		float z;
	public:
		float Width;
		float Height;
	};

	// TODO: add SliderInt
	class SliderFloat {
	public:
		float Min;
		float Max;
	public:		
		void SetRange(float arg_min, float arg_max);		
	};

	class Dropdown {
	private:
		int[] sz_str_item;
	public:		
		int[] GetItems() {
			return sz_str_item;
		}
	public:
		//use fmt
		void AddItem(int arg_text);
		void RemoveItem(int arg_text);
		bool HasItem(int arg_text) {
			return false;
		}
	};

	class Image{ };
	class ComboBox{ 
	public:
		bool BeginComboBox() {
			return false;
		}
		bool ComboBox(int arg_label) {
			return false;
		}
		void EndComboBox();
	};
	class VerticalLayout{ };
	class HorizontalLayout{ };
	class Color4{ };	
}

#pragma once

class Button {
	public:
			DWORD* _this;

			Button(DWORD* ButtonPointer)
			{
				_this = ButtonPointer;
			}

			bool IsEqual(DWORD* Ref)
			{
				if (_this == Ref)
					return true;
				else
					return false;
			}
};
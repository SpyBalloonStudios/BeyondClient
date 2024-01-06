#pragma once


namespace Render
{
    Camera Cam = Camera();

    float GetDistance(Vector3 Position)
    {
        return Cam.GetDistance(Position);
    }

    float GetFov()
    {
        return Cam.Fov;
    }

    void Zoom()
    {
        Cam.Zoom();
    }
    
    void DontZoom()
    {
        Cam.DontZoom();
    }

    float DivideWithDistance(Vector3 Position, float size)
	{
		return size / GetDistance(Position);
	}
    Vec2 DivideWithDistance(Vector3 Position, Vec2 size)
    {
        return Vec2(DivideWithDistance(Position, size.x), DivideWithDistance(Position, size.y));
    }

    float ReverseDivideWithDistance(Vector3 Position, float value)
	{
		return GetDistance(Position) / value;
	}

    bool IsOnScreen(Vector3 Position)
	{
        Vector3 ScreenPos = Cam.WorldToScreenPoint(Position);
        if (GetDistance(Position) > 0.0f && ScreenPos.x > 0 && ScreenPos.y > 0 && ScreenPos.z > 0)
            return true;
        else
		    return false;
	}

    void RenderNamePlate_(ImVec2 Position, float Size, std::string Displayname, std::string ExtraInfo)
    {
        ImVec2 DisplaynameTextSize = ImGui::CalcTextSize(Displayname.c_str());
        ImVec2 ExtraInfoTextSize = ImGui::CalcTextSize(ExtraInfo.c_str());
        ImColor Color = ImColor(0.0f, 0.0f, 0.0f, 0.7f);
        ImColor TextColor = ImColor(1.f, 1.f, 1.f, 1.f);

        ImGui::GetBackgroundDrawList()->AddRectFilled(
            ImVec2(Position.x - (DisplaynameTextSize.x * 1.5), Position.y - (DisplaynameTextSize.y / 2)),
            ImVec2(Position.x + (DisplaynameTextSize.x + (DisplaynameTextSize.x * 1.5)), Position.y + (DisplaynameTextSize.y + (DisplaynameTextSize.y / 2))),
            Color,
            8.f
        );

        ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), Size, Position, TextColor, Displayname.c_str());
    }

    void RenderPlayerNamePlate(Player p)
    {
        Vector3 PlayerHead = p.GetBonePosition(Head);

        Vector3 Anchor = Vector3(PlayerHead.x, PlayerHead.y + 0.5f, PlayerHead.z);
        if (IsOnScreen(Anchor))
        {
            Vector3 ScreenPos = Cam.WorldToScreenPoint(Anchor);

            RenderNamePlate_(ImVec2(ScreenPos.x, (float)GetSystemMetrics(SM_CYSCREEN) - ScreenPos.y), DivideWithDistance(Anchor, 10.f), p.DisplayName, "");
        }
    }

    void DrawTextWorldSpace(Vector3 Position, std::string Text, ImColor Color = ImColor(1.0f, 1.0f, 1.0f, 1.0f), float FrontSize = 15.0f, bool ScaleWithDistance = false)
    {
        if (IsOnScreen(Position))
        {
            Vector3 ScreenPos = Cam.WorldToScreenPoint(Position);

            if(ScaleWithDistance)
                Gui.Text(Text.c_str(), Vec2(ScreenPos.x, (float)GetSystemMetrics(SM_CYSCREEN) - ScreenPos.y), Color, DivideWithDistance(Position, FrontSize), true);
            else
                Gui.Text(Text.c_str(), Vec2(ScreenPos.x, (float)GetSystemMetrics(SM_CYSCREEN) - ScreenPos.y), Color, 15.0f, true);
        }
    }
    void DrawBoxWorldSpace(Vector3 Position, Vec2 BoxSize, float Thickness, float Roundness, ImColor Color = ImColor(1.0f, 1.0f, 1.0f, 1.0f), float glowintensity = 0.0f)
    {
        if (IsOnScreen(Position))
        {
            Vector3 ScreenPos = Cam.WorldToScreenPoint(Position);
            Gui.Rectangle(Vec2(ScreenPos.x - (BoxSize.x / 4), (float)GetSystemMetrics(SM_CYSCREEN) - ScreenPos.y), DivideWithDistance(Position, BoxSize), Color, Thickness, ReverseDivideWithDistance(Position, Roundness));
        }
    }
    void DrawLineToLowerScreenWorldSpace(Vector3 Beginning, float Thickness, ImColor Color = ImColor(1.0f, 1.0f, 1.0f, 1.0f))
    {
        Vector3 BeginningScreenPos = Cam.WorldToScreenPoint(Beginning);

        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);

        Vec2 End;

        switch (Config::Render::DirectLines::Type)
        {
            case UpperScreen:
                End = Vec2(screenWidth / 2, 0);
                break;
            case MiddleScreen:
                End = Vec2(screenWidth / 2, screenHeight / 2);
                break;
            case LowerScreen:
                End = Vec2(screenWidth / 2, screenHeight);
                break;
            case FromCursor:
                POINT cursorPos;
                GetCursorPos(&cursorPos);
                End = Vec2(cursorPos.x, cursorPos.y);
        }
        Gui.Line(Vec2(BeginningScreenPos.x, (float)screenHeight - BeginningScreenPos.y), End, Color, Thickness);
    }

    void DrawPosition(Vector3 Position, float Thickness, ImColor Color = ImColor(1.0f, 1.0f, 1.0f, 1.0f))
    {
        Vector3 BeginningScreenPos = Cam.WorldToScreenPoint(Position);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        Gui.Text(Position.ToString(), Vec2(BeginningScreenPos.x, (float)screenHeight - BeginningScreenPos.y + 30), Color, 15.0f, true);
    }
    
    void RenderPlayerESP(Player player)
    {
        Vector3 PlayerPosition = player.GetPosition();

        Vector3 HeadPosition = player.GetBonePosition(Head);

        Vec2 BoxSize((HeadPosition.y / 2) * Config::Render::ESP::Size, HeadPosition.y * Config::Render::ESP::Size);
        Render::DrawBoxWorldSpace(HeadPosition, BoxSize, Config::Render::ESP::Thickness, Config::Render::ESP::Roundness, Config::Render::ESP::Color, Config::Render::ESP::GlowIntensity);
    }

    void RenderLineESP(Player player)
    {
        if (!player.GetApiUser().IsSelf)
        {
            vrcplayer vrc(player.__this);
            Transform PTransform(vrc.GetParent());
            Vector3 PlayerPosition = player.GetBonePosition(Chest);

            if (IsOnScreen(PlayerPosition))
            {
                DrawLineToLowerScreenWorldSpace(PlayerPosition, Config::Render::DirectLines::Thickness, Config::Render::DirectLines::Color);
            }
        }
    }

    void RemderPosition(Player player)
    {
        vrcplayer vrc(player.__this);
        Transform PTransform(vrc.GetParent());
        Vector3 PlayerPosition = PTransform.GetPosition();

        DrawPosition(PlayerPosition, Config::Render::Thickness, Config::Render::DirectLines::Color);
    }

    void RenderNamePlate(Player player, std::string Extrainfo = "")
    {
        std::string DisplayName = player.GetApiUser().DisplayName;
        if (Extrainfo != "")
        {
            DisplayName = DisplayName  + " [" + Extrainfo + "]";
        }

        vrcplayer vrc(player.__this);
        Transform PTransform(vrc.GetParent());
        Vector3 PlayerPosition = PTransform.GetPosition();

        DrawTextWorldSpace(PlayerPosition, DisplayName, Config::Render::NamePlate::Color, Config::Render::NamePlate::Size);
    }

    void DrawClientCursor()
    {
        if (Config::Render::Cursor::Enabled)
        {
            POINT cursorPos;
            if (GetCursorPos(&cursorPos))
            {
                int x = cursorPos.x - 2;
                int y = cursorPos.y - 15;
                ImVec2 center = ImVec2(x, y);

                switch (Config::Render::Cursor::Type)
                {
                    case FilledCursor:
                        Gui.Text((std::to_string(x) + " " + std::to_string(y)), Vec2(x, y + 20), ImColor(1.0f, 1.0f, 1.0f, 1.0f), 15.0f);
                        Gui.CircleFilled(ImVec2(x, y), Config::Render::Cursor::Radius, Config::Render::Cursor::Color, Config::Render::Saturation::Value);
                        break;
                    case HollowCursor:
                        ImGui::GetForegroundDrawList()->AddCircle(center, Config::Render::Cursor::Radius, Config::Render::Cursor::Color, 50, Config::Render::Cursor::Thickness);
                        //Gui.Circle(ImVec2(x, y), Config::Render::Cursor::Radius, Config::Render::Cursor::Color, Config::Render::Saturation::Value, Config::Render::Cursor::Thickness);
                        break;
                }
            }
        }
    }

    void Render(Player p)
    {
        if (p.isValid())
        {
            if (Config::Render::DirectLines::Enabled)
            {
                RenderLineESP(p);
            }
            if (Config::Render::NamePlate::Enabled)
            {
                RenderPlayerNamePlate(p);

                /*
                if (p.isEqual(Players::SelectedPlayer))
                {
                    RenderNamePlate(p, "Selected");
                }
                else {
                    RenderNamePlate(p);
                }
                */
                
            }
            if (Config::Render::ESP::Enabled)
            {
                RenderPlayerESP(p);
            }
            if (Config::Render::Position::Enabled)
            {
                RemderPosition(p);
            }
        }
    }
}

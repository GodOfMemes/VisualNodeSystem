#include "GroupComment.h"
using namespace VisNodeSys;

char GroupComment::GroupCommentRename[GROUP_COMMENT_CAPTION_MAX_LENGHT] = "";

GroupComment::GroupComment(const std::string ID)
{
	this->ID = ID;
	if (ID.empty())
		this->ID = NODE_CORE.GetUniqueHexID();

	SetSize(ImVec2(200, 200));
}

GroupComment::GroupComment(const GroupComment& Src)
{
	ParentArea = Src.ParentArea;
	ID = NODE_CORE.GetUniqueHexID();
	Position = Src.Position;
	Size = Src.Size;
	Caption = Src.Caption;
	bMoveElementsWithComment = Src.bMoveElementsWithComment;
	BackgroundColor = Src.BackgroundColor;
}

std::string GroupComment::GetID()
{
	return ID;
}

ImVec2 GroupComment::GetPosition() const
{
	return Position;
}

void GroupComment::SetPosition(const ImVec2 NewValue)
{
	Position = NewValue;
}

ImVec2 GroupComment::GetSize() const
{
	return Size;
}

void GroupComment::SetSize(const ImVec2 NewValue)
{
	Size = NewValue;
}

void GroupComment::Draw() {}

nlohmann::ordered_json GroupComment::ToJson()
{
	nlohmann::ordered_json result;

	result["ID"] = ID;
	result["position"]["x"] = Position.x;
	result["position"]["y"] = Position.y;
	result["size"]["x"] = Size.x;
	result["size"]["y"] = Size.y;
	result["caption"] = Caption;
	result["bMoveElementsWithComment"] = bMoveElementsWithComment;
	result["BackgroundColor"]["x"] = BackgroundColor.x;
	result["BackgroundColor"]["y"] = BackgroundColor.y;
	result["BackgroundColor"]["z"] = BackgroundColor.z;
	result["BackgroundColor"]["w"] = BackgroundColor.w;

	return result;
}

void GroupComment::FromJson(nlohmann::ordered_json Json)
{
	Json.at("ID").get_to(ID);
	Json.at("position").at("x").get_to(Position.x);
	Json.at("position").at("y").get_to(Position.y);
	Json.at("size").at("x").get_to(Size.x);
	Json.at("size").at("y").get_to(Size.y);
	Json.at("caption").get_to(Caption);
	Json.at("bMoveElementsWithComment").get_to(bMoveElementsWithComment);
	Json.at("BackgroundColor").at("x").get_to(BackgroundColor.x);
	Json.at("BackgroundColor").at("y").get_to(BackgroundColor.y);
	Json.at("BackgroundColor").at("z").get_to(BackgroundColor.z);
	Json.at("BackgroundColor").at("w").get_to(BackgroundColor.w);
}

bool GroupComment::IsHovered() const
{
	return bHovered;
}

bool GroupComment::IsSelected() const
{
	return bSelected;
}

NodeArea* GroupComment::GetParentArea() const
{
	return ParentArea;
}

void GroupComment::SetCaption(std::string NewValue)
{
	Caption = NewValue;
}

std::string GroupComment::GetCaption() const
{
	return Caption;
}

float GroupComment::GetCaptionHeight(float Zoom) const
{
	return 50.0f * Zoom;
}

ImVec2 GroupComment::GetCaptionSize(float Zoom) const
{
	return ImVec2((GetSize() * Zoom).x - 8.0f * Zoom, GetCaptionHeight(Zoom));
}

bool GroupComment::MoveElementsWithComment() const
{
	return bMoveElementsWithComment;
}

void GroupComment::SetMoveElementsWithComment(bool NewValue)
{
	bMoveElementsWithComment = NewValue;
}
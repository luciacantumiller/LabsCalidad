#pragma once
class CommentLines {
public:
	CommentLines();
	int getCommentLines();
	void setCommentLines();
private:
	int blank_lines;
};

CommentLines::CommentLines() {
	this->blank_lines = 0;
}

int CommentLines::getCommentLines() {
	return blank_lines;
}

void CommentLines::setCommentLines() {
	blank_lines++;
}
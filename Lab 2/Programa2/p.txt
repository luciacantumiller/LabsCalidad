class BlankLines {
public:
	BlankLines();
	int getBlankLines();
	void setBlankLines();
private:
	int blank_lines;
};

BlankLines::BlankLines() {
	this->blank_lines = 0;
}

int BlankLines::getBlankLines() {
	return blank_lines;
}

void BlankLines::setBlankLines() {
	blank_lines++;
}
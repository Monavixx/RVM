#pragma once
class AnatarClass
{
public:
	AnatarClass(char* name);
	void SetName(char* name);
	char* GetName() const;
private:
	char* name;
};


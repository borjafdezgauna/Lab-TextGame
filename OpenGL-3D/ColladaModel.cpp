#include "ColladaModel.h"



ColladaModel::ColladaModel(const char *filename)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(filename);
	
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");
	tinyxml2::XMLElement* init_from = pRoot->FirstChildElement("library_images") -> FirstChildElement("image") -> FirstChildElement("init_from");
	
	const char* textura = init_from->GetText();

	textureId = SOIL_load_OGL_texture(&textura[8], 0, 0, 0);




}

void ColladaModel::parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> &vector)
{
	char* pCharArray = (char *)pFloatArray->GetText();
	char* nextToken;
	char* pt = strtok_s(pCharArray, "", &nextToken);
	while (pt != 0)
	{
		vector.push_back( atof(pt));
		pt = strtok_s(0, " ", &nextToken);
	}
}

void ColladaModel::parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, std::vector<int> &vector)
{
	char* pCharArray = (char*)pFloatArray->GetText();
	char* nextToken;
	char* pt = strtok_s(pCharArray, " ", &nextToken);
	while (pt != 0)
	{
		vector.push_back( atoi(pt));
		pt = strtok_s(0, "", &nextToken);
	}
}
ColladaModel::~ColladaModel()
{
}

void ColladaModel::draw() 
{
}
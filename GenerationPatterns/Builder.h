#pragma once
#include <string>
using std::string;

struct Document
{
	string Title;
	string Type;
	string Body;
};

struct IDocumentBuilder
{
protected:
	Document* document;
public:
	IDocumentBuilder();
	virtual void setTitle() = 0;
	virtual void setType() = 0;
	virtual void setBody() = 0;
	virtual Document* getResult() = 0;
};

struct ExcelDocumentBuilder : IDocumentBuilder
{
	using IDocumentBuilder::IDocumentBuilder;
	void setTitle() override;
	void setType() override;
	void setBody() override;
	Document* getResult() override;
};

struct PdfDocumentBuilder : IDocumentBuilder
{
	using IDocumentBuilder::IDocumentBuilder;
	void setTitle() override;
	void setType() override;
	void setBody() override;
	Document* getResult() override;
};

struct DocumentCreator
{
private:
	IDocumentBuilder* builder;
public:
	DocumentCreator(IDocumentBuilder* builder);
	Document* createDocument();
	~DocumentCreator();
};
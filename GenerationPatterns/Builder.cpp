#include "Builder.h"

IDocumentBuilder::IDocumentBuilder() : document(new Document()){}

void ExcelDocumentBuilder::setTitle()
{
	this->document->Title = "ExcelDocumentTitle";
}

void ExcelDocumentBuilder::setType()
{
	this->document->Type = "Excel";
}

void ExcelDocumentBuilder::setBody()
{
	this->document->Body = "ExcelDocumentBody";
}

Document* ExcelDocumentBuilder::getResult()
{
	return this->document;
}

void PdfDocumentBuilder::setTitle()
{
	this->document->Title = "PdfDocumentTitle";
}

void PdfDocumentBuilder::setType()
{
	this->document->Type = "Pdf";
}

void PdfDocumentBuilder::setBody()
{
	this->document->Body = "PdfDocumentBody";
}

Document* PdfDocumentBuilder::getResult()
{
	return this->document;
}

DocumentCreator::DocumentCreator(IDocumentBuilder* builder) : builder(builder){}

Document* DocumentCreator::createDocument()
{
	this->builder->setTitle();
	this->builder->setType();
	this->builder->setBody();
	return this->builder->getResult();
}

DocumentCreator::~DocumentCreator()
{
	delete builder;
}
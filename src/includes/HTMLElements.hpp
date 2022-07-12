#ifndef _HTML_ELEMENTS_HPP
#define _HTML_ELEMENTS_HPP

#include <vector>
#include <string>
#include <map>
#include "Warn.hpp"

#define EMPTY_ATTRTABLE (AttributesTable())

namespace BlogGen {
	
	class AttributesTable {
		private:
			std::vector<std::string> 					attrNames;
			std::map<std::string, std::string> 				attrContents;
			bool								empty;
		public:
			AttributesTable() {
				attrNames.clear();
				empty = true;
			}
			void isEmpty() {
				return empty;
			}
			void setAttribute(std::string attrName, std::string attrContent) {
				attrNames.push_back(attrName);
				if (attrContents[attrContent] != "") {
					string warnMsg = "WARNING: Changing a non-empty attribute \"" + attrName + "\"";
					warnCLI(warnMsg);
				}
				attrContents[attrName] = attrContent;
			}
		std::vector<std::string> getAttrNames() {
			return attrNames;
		}
		std::map<std::string, std::string> getAttrContents() {
			return attrContents;
		}
	};
	
	class Element {
		private:
			std::string name;
			bool end;
		public:
			Element() {
				name 		= "";
				end		= true;
			}
			Element(std::string Name, bool End = true) {
				name 	= Name;
				end 	= End;
			}
			Element(const char* Name, bool End = true) {
				name		= std::string(Name);
				end		= End;
			}
			std::string create(std::string content, AttributesTable attrTable = EMPTY_ATTRTABLE) {
				std::string ret = std::string("<") + name + std::string(" ");
				if (!(attrTable.isEmpty()) {
					vector<std::string> 		attrNames 	= attrTable.getAttrNames();
					map<std::string, std::string> 	attrContents	= attrTable.getAttrContents();
					for (unsigned int i = 0; i < attrNames.size(); i++) {
						ret += attrNames[i] + std::string("=") + std::string("\"") + attrContents[attrNames[i]] + std::string("\" ");
					}
				}
				if (end) {
					ret += std::string(">") + content + std::string("</") + name + std::string(">");
				} else {
					ret += std::string(" />");
				}
				return ret;
			}
			std::string create(AttributesTable attrTable = EMPTY_ATTRTABLE) {
				std::string ret = std::string("<") + name + std::string(" ");
				if (!(attrTable.isEmpty())) {
					vector<std::string> 		attrNames 	= attrTable.getAttrNames();
					map<std::string, std::string> 	attrContents	= attrTable.getAttrContents();
					for (unsigned int i = 0; i < attrNames.size(); i++) {
						ret += attrNames[i] + std::string("=") + std::string("\"") + attrContents[attrNames[i]] + std::string("\" ");
					}
				}
				if (end) {
					ret += std::string(">") + std::string("</") + name + std::string(">");
				} else {
					ret += std::string(" />");
				}
				return ret;
			}
	};
	
	Element 	h1 			= Element("h1"), 			// Heading 1
			h2 			= Element("h2"), 			// Heading 2
			h3 			= Element("h3"), 			// Heading 3
			h4 			= Element("h4"), 			// Heading 4
			h5 			= Element("h5"), 			// Heading 5
			h6 			= Element("h6"), 			// Heading 6
			p			= Element("p"),				// Paragraph
			em			= Element("em"),			// Italicized
			strong			= Element("strong"),			// Bold
			code			= Element("code"),			// Monospaced
			hr			= Element("hr", false),			// Horizontal
			ol			= Element("ol"),			// Ordered list
			li			= Element("li"),			// List items
			ul			= Element("ul"),			// Unordered list
			a			= Element("a"),				// Hyperlink
			blockquote		= Element("blockquote"),		// Blockquote
			img			= Element("img");			// Image
			
	
};
#endif

/* 
 * XML Serializer
 * @author Vermeille Guillaume <Guillaume.v.sanchez@gmail.com>
 * @modified by ECHOES Technologies <contact@echoes-tech.com> 
 * @date 15/11/2013
 * 
 * Copyright (C) 2013 ECHOES TECHNOLGIES SAS <contact@echoes-tech.com> 
 * Copyright (C) 2012 Vermeille Guillaume <Guillaume.v.sanchez@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial 
 * portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT 
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef XMLSERIALIZER_H
#define	XMLSERIALIZER_H

#include <Wt/WDateTime>
#include <Wt/Dbo/Dbo>

namespace Wt
{
  namespace Dbo
  {

    class XmlSerializer {
    public:

        XmlSerializer(std::ostream& out, Session& s) : out_(out), s_(s) {
            indent_ = 1;
        }

        template <class V>
        void act(Wt::Dbo::FieldRef< V> field) {
            Indent();
            out_ << "<" << field.name() << ">" 
                    << field.value()
                    << "</" << field.name() << ">" 
                    << std::endl;
        }
        void act(Wt::Dbo::FieldRef< Wt::WDateTime> field) {
            Indent();
            out_ << "<" << field.name() << ">" 
                    << field.value().toString().toUTF8()
                    << "</" << field.name() << ">" 
                    << std::endl;
        }
        
        template <class V>
        void actPtr(Wt::Dbo::PtrRef< V> field) {
            Indent();
            out_ << "<" << s_.tableName<V>() << ">" << std::endl;
            ++indent_;
                Indent();
                out_ << "<id>" << field.id() << "</id>" << std::endl;
            --indent_;
            Indent();
            out_ << "</" << s_.tableName<V>() << ">" << std::endl;
        }

        template <class V>
        void actCollection(const Wt::Dbo::CollectionRef< V> & collec) {
            Indent();
            out_ << "<" << s_.tableName<V>() << "s>" << std::endl;
            ++indent_;
            for (Wt::Dbo::ptr<V> &field : collec.value()) {
                Indent();
                out_ << "<id>" << field.id() << "</id>" << std::endl;
            }
            --indent_;
            Indent();
            out_ << "</" << s_.tableName<V>() << "s>" << std::endl;
        }

        template <class C>
        void Serialize(C& c) const {
            c.persist(this);
        }

        template <class C>
        void Serialize(Wt::Dbo::ptr< C> & c) {
            Indent();
            out_ << "<" << s_.tableName<C>() << ">" << std::endl;
            ++indent_;
            const_cast<C&> (*c).persist(*this);
            --indent_;
            Indent();
            out_ << "</" << s_.tableName<C>() << ">" << std::endl;
        }

        template <class C>
        void Serialize(Wt::Dbo::collection< Wt::Dbo::ptr< C> >& cs) {
            Indent();
            out_ << "<" << s_.tableName<C>() << "s>" << std::endl;
            ++indent_;
            for (auto& c : cs) {
                Serialize(c);
            }
            --indent_;
            Indent();
            out_ << "</" << s_.tableName<C>() << "s>" << std::endl;
        }
        
        Session *session() { return &s_; }
    private:

        void Indent(void) const {
            for (int i = 0; i < indent_; ++i)
                out_ << "  ";
        }
        std::ostream& out_;
        Session& s_;
        int indent_;
    };

  }
}

#endif	/* XMLSERIALIZER_H */


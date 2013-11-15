/* 
 * Json Serializer
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

#ifndef JSONSERIALIZER_H
#define	JSONSERIALIZER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <Wt/WDateTime>
#include <Wt/Dbo/Dbo>
#include <Wt/Auth/Dbo/AuthInfo>

#include "user/User.h"

namespace Wt
{
  namespace Dbo
  {

    class JsonSerializer {
    public:

        JsonSerializer(std::ostream& out, Session& s) : out_(out), s_(s) {
//            indent_ = 1;
        }

        std::string transformFieldName(const std::string& fieldName)
        {
            std::string res = fieldName;
            std::transform(res.begin(), res.end(), res.begin(), ::tolower);
            res.erase(0, res.find_first_of("_") + 1);
            return res;
        }
        std::string transformTableName(const std::string& fieldTable)
        {
            std::string res = fieldTable;
            // Check if fieldTable has more than 1 '_'
            if (res.find_first_of("_") != res.find_last_of("_"))
            {
                res =  transformFieldName(fieldTable);
                res.erase(res.find_last_of("_"));
            }
            return res;
        }
        
        template <class V>
        void act(Wt::Dbo::FieldRef< V> field) {
            root.put(transformFieldName(field.name()), field.value());
        }
        void act(Wt::Dbo::FieldRef< Wt::WDateTime> field) {
            root.put(transformFieldName(field.name()), field.value().toString().toUTF8());
        }
        
        template <class V>
        void actPtr(Wt::Dbo::PtrRef< V> field) {
            boost::property_tree::ptree elem;
            if (field.id() > 0)
            {
                if (field.value().get()->deleteTag.isNull())
                {
                    elem.put("id", field.id());
                    // A NE PAS SUPPRIMER
    //            const_cast<V&> (*field.value().get()).persist(*this);
                    root.put_child(transformTableName(s_.tableName<V>()), elem);
                }
            }
        }
        void actPtr(Wt::Dbo::PtrRef< Wt::Auth::Dbo::AuthInfo<Echoes::Dbo::User>> field) {
            
        }
        
        template <class V>
        void actCollection(const Wt::Dbo::CollectionRef< V> & collec) {
//            boost::property_tree::ptree arr;

//            for (Wt::Dbo::ptr<V> &field : collec.value()) {
//                if (field.isTransient()) {
//                    if (field.value().get()->deleteTag.isNull()) {
//                        boost::property_tree::ptree elem;
//                        elem.put("id", field.id());
//                        arr.push_back(std::make_pair("", elem));
//                    }
//                }
//            }
            long long i = 0;
            for (Wt::Dbo::ptr<V> &field : collec.value()) {
                if (field.isTransient()) {
                    if (field.get()->deleteTag.isNull()) {
                        i++;
                    }
                }
            }
//            root.put<long long>(transformTableName(s_.tableName<V>()), i);
            const std::string tmp = transformTableName(s_.tableName<V>());
            std::cout << "qu'avons nous là ? " << tmp << std::endl;
            root.put<long long>(tmp, i);
        }
        void actCollection(const Wt::Dbo::CollectionRef< Wt::Auth::Dbo::AuthInfo<Echoes::Dbo::User>> & collec) {

        }
        void actCollection(const Wt::Dbo::CollectionRef< Echoes::Dbo::Organization> & collec) {

        }

        template <class C>
        void Serialize(C& c) const {
            c.persist(this);
        }

        template <class C>
        void Serialize(Wt::Dbo::ptr< C> & c) {
            if (c->deleteTag.isNull())
            {
                root.put("id", c.id());
                const_cast<C&> (*c).persist(*this);
            }

            std::stringstream ss;
            boost::property_tree::json_parser::write_json(ss, root);

            out_ <<  ss.str();
        }
        void Serialize(Wt::Dbo::ptr< Wt::Auth::Dbo::AuthInfo<Echoes::Dbo::User>> & c) {

        }

        template <class C>
        void Serialize(Wt::Dbo::collection< Wt::Dbo::ptr< C> >& cs) {
//            Indent();
//            out_ << "<" << s_.tableName<C>() << "s>" << std::endl;
//            ++indent_;
            for (auto& c : cs) {
                Serialize(c);
            }
//            --indent_;
//            Indent();
//            out_ << "</" << s_.tableName<C>() << "s>" << std::endl;
        }
        void Serialize(Wt::Dbo::collection< Wt::Dbo::ptr< Wt::Auth::Dbo::AuthInfo<Echoes::Dbo::User>> >& cs) {
            
        }
        
        Session *session() { return &s_; }
    private:

        std::ostream& out_;
        Session& s_;
//        int indent_;
        boost::property_tree::ptree root;
    };

  }
}

#endif	/* JSONSERIALIZER_H */


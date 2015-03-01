/*
 * EDA4U - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://eda4u.ubruhin.ch/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBRARY_SYMBOLPIN_H
#define LIBRARY_SYMBOLPIN_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include "../common/units/all_length_units.h"
#include "../common/file_io/if_xmlserializableobject.h"

/*****************************************************************************************
 *  Class SymbolPin
 ****************************************************************************************/

namespace library {

/**
 * @brief The SymbolPin class
 */
class SymbolPin final : public IF_XmlSerializableObject
{
        Q_DECLARE_TR_FUNCTIONS(SymbolPin)

    public:

        // Constructors / Destructor
        explicit SymbolPin(const QUuid& uuid = QUuid::createUuid(),
                           const QString& name_en_US = QString(),
                           const QString& description_en_US = QString()) noexcept;
        explicit SymbolPin(const XmlDomElement& domElement) throw (Exception);
        ~SymbolPin() noexcept;

        // Getters
        const QUuid& getUuid() const noexcept {return mUuid;}
        const Point& getPosition() const noexcept {return mPosition;}
        const Length& getLength() const noexcept {return mLength;}
        const Angle& getAngle() const noexcept {return mAngle;}
        QString getName(const QString& locale = QString()) const noexcept;
        QString getDescription(const QString& locale = QString()) const noexcept;
        const QHash<QString, QString>& getNames() const noexcept {return mNames;}
        const QHash<QString, QString>& getDescriptions() const noexcept {return mDescriptions;}

        // Setters
        void setPosition(const Point& pos) noexcept;
        void setLength(const Length& length) noexcept;
        void setAngle(const Angle& angle) noexcept;
        void setName(const QString& locale, const QString& name) noexcept;
        void setDescription(const QString& locale, const QString& description) noexcept;

        // General Methods
        XmlDomElement* serializeToXmlDomElement() const throw (Exception);

    private:

        // make some methods inaccessible...
        SymbolPin(const SymbolPin& other);
        SymbolPin& operator=(const SymbolPin& rhs);

        // Private Methods
        bool checkAttributesValidity() const noexcept;


        // Pin Attributes
        QUuid mUuid;
        Point mPosition;
        Length mLength;
        Angle mAngle;
        QHash<QString, QString> mNames;
        QHash<QString, QString> mDescriptions;
};

} // namespace library

#endif // LIBRARY_SYMBOLPIN_H

/*
* This file is part of educazionik-framework
*
* Copyright (C) 2014 Nicola De Filippo.
*
* Contact: Nicola De Filippo <nicola@nicoladefilippo.it> or <nicola.defilippo@lizard-solutions.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
* 02110-1301 USA
*
*/


import QtQuick 2.0

Rectangle {
    width: 200
    height: 62

    Text {
        id: esattiText
        text: qsTr("0")
        anchors.left: parent.left
        font.pixelSize: parent.height
    }
    Text {
        id: erratiText
        text: qsTr("0")
        anchors.right: parent.right
        font.pixelSize: parent.height

    }
    function esatto() {
        var dum = Number(esattiText.text) + 1;
        esattiText.text = dum.toString();
    }
    function errato() {
        var dum = Number(erratiText.text) + 1;
        erratiText.text = dum.toString();
    }
}

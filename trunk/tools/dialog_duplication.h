/***************************************************************************
**                                                                        **
**  Polyphone, a soundfont editor                                         **
**  Copyright (C) 2013-2017 Davy Triponney                                **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Davy Triponney                                       **
**  Website/Contact: http://polyphone-soundfonts.com                      **
**             Date: 01.01.2013                                           **
***************************************************************************/

#ifndef DIALOG_DUPLICATION_H
#define DIALOG_DUPLICATION_H

#include <QDialog>

namespace Ui {
class DialogDuplication;
}

class DialogDuplication : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDuplication(bool isPrst, QWidget *parent = 0);
    ~DialogDuplication();
    
signals:
    void accepted(QVector<QPair<int, int> > listeVelocite, bool duplicKey, bool duplicVel);

private slots:
    void accept();
    void on_pushAdd_clicked();
    void on_pushRemove_clicked();
    void on_spinMinVel_valueChanged(int arg1);
    void on_spinMaxVel_valueChanged(int arg1);
    void on_checkForEachVelocityRange_clicked();

    void on_listVelocites_currentRowChanged(int currentRow);

private:
    Ui::DialogDuplication *ui;
    bool _isPrst;
    QVector<QPair<int, int> > _listeVelocites;

    void dispVel();
    QVector<QPair<int, int> > getStoredVelocites();
    void storeVelocities(QVector<QPair<int, int> > val);
};

#endif // DIALOG_DUPLICATION_H

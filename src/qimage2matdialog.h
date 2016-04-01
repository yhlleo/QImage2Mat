#ifndef QIMAGE2MATDIALOG_H
#define QIMAGE2MATDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>

#include "cv.h"
#include "highgui.h"

using namespace cv;

namespace Ui {
class QImage2MatDialog;
}

class QImage2MatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QImage2MatDialog(QWidget *parent = 0);
    ~QImage2MatDialog();

public:
	void qimageShow(QImage& qImage, QGraphicsView*& graphView);

	void mat2qImageShow(QString& imagePath);

	void qImage2MatShow(QImage& qImage);

	void qImage2MatPtrShow(QImage& qImage);

	QImage mat2QImage(cv::Mat& image);

	cv::Mat qImage2Mat(QImage& qImg);

	cv::Mat qImage2MatPtr(QImage& qImg);

	bool isPicture(QString& imagePath);

private slots:
    void on_pushButton_clicked();

private:
    Ui::QImage2MatDialog *ui;
    QString _imageFilePath;
};

#endif // QIMAGE2MATDIALOG_H

/* 
 * File:   util.h
 * Author: anton
 *
 * Created on 2 Февраль 2016 г., 15:02
 */

#ifndef UTIL_H
#   define	UTIL_H

#ifndef NOGUI
#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>
QImage cvMatToQImage( cv::Mat const & frame );
#endif

#endif	/* UTIL_H */


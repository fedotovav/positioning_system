#include <iostream>

#include "gui.h"

gui::gui( obj_track_t * ot, QWidget* parent ) :
     QMainWindow(parent)
   , ui_        (new Ui::gui)
   , obj_track_ (ot)
{
   ui_->setupUi(this);

   this->connect(obj_track_, SIGNAL(frame_is_ready(QImage)), SLOT(redraw(QImage)));
   
   ui_->retranslateUi(this);
   
   cr_win_ = new color_range    (obj_track_);
   cs_win_ = new camera_settings(obj_track_);

   connect(ui_->ot_color_range, SIGNAL(triggered()), this, SLOT(call_color_range_win()));
   connect(ui_->camera_settings, SIGNAL(triggered()), this, SLOT(call_camera_settings_win()));
   connect(ui_->store_settings, SIGNAL(triggered()), this, SLOT(call_camera_settings_save_win()));
}

Q_SLOT void gui::redraw( QImage image )
{
   ui_->label_pic->setPixmap(QPixmap::fromImage(image));
}

void gui::closeEvent( QCloseEvent* event )
{
   obj_track_->stop();
   
   if (cr_win_->isEnabled())
      cr_win_->close();

   if (cs_win_->isEnabled())
      cs_win_->close();
}

Q_SLOT void gui::call_color_range_win()
{
   cr_win_->show();
}

Q_SLOT void gui::call_camera_settings_win()
{
   cs_win_->show();
}

Q_SLOT void gui::call_camera_settings_save_win()
{
   obj_track_->save_camera_hardware_settings();
   
   std::cout << "Camera settings saved" << std::endl;
}

gui::~gui()
{
   delete cr_win_;
   delete cs_win_;
   delete ui_;
}

///////////////////////////////////////
/// color range window
///////////////////////////////////////

color_range::color_range( obj_track_t * object_track, QWidget* parent ) :
     QMainWindow (parent)
   , color_range_(new Ui::color_range)
   , obj_track_  (object_track)
{
   color_range_->setupUi(this);
   
   color_range_->retranslateUi(this);
   
   connect(color_range_->hue_min, SIGNAL(valueChanged(int)), this, SLOT(set_h_min(int)));
   connect(color_range_->hue_max, SIGNAL(valueChanged(int)), this, SLOT(set_h_max(int)));
   connect(color_range_->saturation_min, SIGNAL(valueChanged(int)), this, SLOT(set_s_min(int)));
   connect(color_range_->saturation_max, SIGNAL(valueChanged(int)), this, SLOT(set_s_max(int)));
   connect(color_range_->value_min, SIGNAL(valueChanged(int)), this, SLOT(set_v_min(int)));
   connect(color_range_->value_max, SIGNAL(valueChanged(int)), this, SLOT(set_v_max(int)));
}

color_range::~color_range()
{
   delete color_range_;
}

Q_SLOT void color_range::set_h_min( int val )
{
   if (val > obj_track_->get_max_h())
      color_range_->hue_min->setValue(obj_track_->get_max_h());
   else
      obj_track_->set_min_h(val);
}

Q_SLOT void color_range::set_h_max( int val )
{
   if (val < obj_track_->get_min_h())
      color_range_->hue_max->setValue(obj_track_->get_min_h());
   else
      obj_track_->set_max_h(val);
}

Q_SLOT void color_range::set_s_min( int val )
{
   if (val > obj_track_->get_max_s())
      color_range_->hue_min->setValue(obj_track_->get_max_s());
   else
      obj_track_->set_min_s(val);
}

Q_SLOT void color_range::set_s_max( int val )
{
   if (val < obj_track_->get_min_s())
      color_range_->hue_max->setValue(obj_track_->get_min_s());
   else
      obj_track_->set_max_s(val);
}

Q_SLOT void color_range::set_v_min( int val )
{
   if (val > obj_track_->get_max_v())
      color_range_->hue_min->setValue(obj_track_->get_max_v());
   else
      obj_track_->set_min_v(val);
}

Q_SLOT void color_range::set_v_max( int val )
{
   if (val < obj_track_->get_min_v())
      color_range_->hue_max->setValue(obj_track_->get_min_v());
   else
      obj_track_->set_max_v(val);
}

///////////////////////////////////////
/// color range window
///////////////////////////////////////

camera_settings::camera_settings( obj_track_t * object_track, QWidget* parent ) :
     QMainWindow     (parent)
   , camera_settings_(new Ui::camera_settings)
   , obj_track_      (object_track)
{
   camera_settings_->setupUi(this);
   
   camera_settings_->retranslateUi(this);
   
   camera_settings_->brightness_hardware->setValue(obj_track_->get_brightness_hwr());
   camera_settings_->contrast_hardware->setValue(obj_track_->get_contrast_hwr());
   camera_settings_->saturation_hardware->setValue(obj_track_->get_saturation_hwr());
   camera_settings_->hue_hardware->setValue(obj_track_->get_hue_hwr());
   camera_settings_->gain_hardware->setValue(obj_track_->get_gain_hwr());
   camera_settings_->exposure_hardware->setValue(obj_track_->get_exposure_hwr());
   camera_settings_->brightness_software->setValue(obj_track_->get_brightness_swr());
   camera_settings_->contrast_software->setValue(obj_track_->get_contrast_swr());
   
   connect(camera_settings_->brightness_hardware, SIGNAL(valueChanged(double)), this, SLOT(set_brightness_hardware(double)));
   connect(camera_settings_->contrast_hardware, SIGNAL(valueChanged(double)), this, SLOT(set_contrast_hardware(double)));
   connect(camera_settings_->saturation_hardware, SIGNAL(valueChanged(double)), this, SLOT(set_saturation_hardware(double)));
   connect(camera_settings_->hue_hardware, SIGNAL(valueChanged(double)), this, SLOT(set_hue_hardware(double)));
   connect(camera_settings_->gain_hardware, SIGNAL(valueChanged(double)), this, SLOT(set_gain_hardware(double)));
   connect(camera_settings_->exposure_hardware, SIGNAL(valueChanged(double)), this, SLOT(set_exposure_hardware(double)));
   connect(camera_settings_->brightness_software, SIGNAL(valueChanged(double)), this, SLOT(set_brightness_software(double)));
   connect(camera_settings_->contrast_software, SIGNAL(valueChanged(double)), this, SLOT(set_contrast_software(double)));
}

camera_settings::~camera_settings()
{
   delete camera_settings_;
}

Q_SLOT void camera_settings::set_brightness_hardware( double val )
{
   obj_track_->set_brightness_hwr(val);
}

Q_SLOT void camera_settings::set_contrast_hardware( double val )
{
   obj_track_->set_contrast_hwr(val);
}

Q_SLOT void camera_settings::set_saturation_hardware( double val )
{
   obj_track_->set_saturation_hwr(val);
}

Q_SLOT void camera_settings::set_hue_hardware( double val )
{
   obj_track_->set_hue_hwr(val);
}

Q_SLOT void camera_settings::set_gain_hardware( double val )
{
   obj_track_->set_gain_hwr(val);
}

Q_SLOT void camera_settings::set_exposure_hardware( double val )
{
   obj_track_->set_exposure_hwr(val);
}

Q_SLOT void camera_settings::set_brightness_software( double val )
{
   obj_track_->set_brightness_swr(val);
}

Q_SLOT void camera_settings::set_contrast_software( double val )
{
   obj_track_->set_contrast_swr(val);
}

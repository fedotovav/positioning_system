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
   
   cr_win_ = new object_params    (obj_track_);
   cs_win_ = new camera_settings(obj_track_);

   connect(ui_->ot_object_params, SIGNAL(triggered()), this, SLOT(call_color_range_win()));
   connect(ui_->camera_settings, SIGNAL(triggered()), this, SLOT(call_camera_settings_win()));
   connect(ui_->store_settings, SIGNAL(triggered()), this, SLOT(call_camera_settings_save_win()));
   connect(ui_->ot_start_recording, SIGNAL(triggered()), this, SLOT(call_record_track()));
   connect(ui_->ot_stop_recording, SIGNAL(triggered()), this, SLOT(call_record_track()));
   connect(ui_->ot_show_track, SIGNAL(triggered()), this, SLOT(call_show_track()));
   connect(ui_->ot_show_mesh, SIGNAL(triggered()), this, SLOT(call_show_mesh()));
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

Q_SLOT void gui::call_record_track()
{
   obj_track_->start_recording_track();
   
   std::cout << "Start recording track" << std::endl;
}

Q_SLOT void gui::call_stop_record_track()
{
   obj_track_->stop_recording_track();
   
   std::cout << "Stop recording track" << std::endl;
}

Q_SLOT void gui::call_show_track()
{
   if (ui_->ot_show_track->isChecked())
      obj_track_->draw_track();
   else
      obj_track_->stop_draw_track();
}

Q_SLOT void gui::call_show_mesh()
{
   if (ui_->ot_show_mesh->isChecked())
      obj_track_->draw_mesh();
   else
      obj_track_->stop_draw_mesh();
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

object_params::object_params( obj_track_t * object_track, QWidget* parent ) :
     QMainWindow (parent)
   , object_params_(new Ui::object_params)
   , obj_track_  (object_track)
{
   object_params_->setupUi(this);
   
   object_params_->retranslateUi(this);
   
   connect(object_params_->hue_min, SIGNAL(valueChanged(int)), this, SLOT(set_h_min(int)));
   connect(object_params_->hue_max, SIGNAL(valueChanged(int)), this, SLOT(set_h_max(int)));
   connect(object_params_->saturation_min, SIGNAL(valueChanged(int)), this, SLOT(set_s_min(int)));
   connect(object_params_->saturation_max, SIGNAL(valueChanged(int)), this, SLOT(set_s_max(int)));
   connect(object_params_->value_min, SIGNAL(valueChanged(int)), this, SLOT(set_v_min(int)));
   connect(object_params_->value_max, SIGNAL(valueChanged(int)), this, SLOT(set_v_max(int)));
   connect(object_params_->obj_size_min, SIGNAL(valueChanged(int)), this, SLOT(set_obj_size_min(int)));
   connect(object_params_->obj_size_max, SIGNAL(valueChanged(int)), this, SLOT(set_obj_size_max(int)));
}

object_params::~object_params()
{
   delete object_params_;
}

Q_SLOT void object_params::set_h_min( int val )
{
   if (val > obj_track_->get_max_h())
      object_params_->hue_min->setValue(obj_track_->get_max_h());
   else
      obj_track_->set_min_h(val);
}

Q_SLOT void object_params::set_h_max( int val )
{
   if (val < obj_track_->get_min_h())
      object_params_->hue_max->setValue(obj_track_->get_min_h());
   else
      obj_track_->set_max_h(val);
}

Q_SLOT void object_params::set_s_min( int val )
{
   if (val > obj_track_->get_max_s())
      object_params_->saturation_min->setValue(obj_track_->get_max_s());
   else
      obj_track_->set_min_s(val);
}

Q_SLOT void object_params::set_s_max( int val )
{
   if (val < obj_track_->get_min_s())
      object_params_->saturation_max->setValue(obj_track_->get_min_s());
   else
      obj_track_->set_max_s(val);
}

Q_SLOT void object_params::set_v_min( int val )
{
   if (val > obj_track_->get_max_v())
      object_params_->value_min->setValue(obj_track_->get_max_v());
   else
      obj_track_->set_min_v(val);
}

Q_SLOT void object_params::set_v_max( int val )
{
   if (val < obj_track_->get_min_v())
      object_params_->value_max->setValue(obj_track_->get_min_v());
   else
      obj_track_->set_max_v(val);
}

Q_SLOT void object_params::set_obj_size_min( int val )
{
   if (val > obj_track_->get_max_obj_size())
      object_params_->obj_size_min->setValue(obj_track_->get_max_obj_size());
   else
      obj_track_->set_min_obj_size(val);
}

Q_SLOT void object_params::set_obj_size_max( int val )
{
   if (val < obj_track_->get_min_obj_size())
      object_params_->obj_size_max->setValue(obj_track_->get_min_obj_size());
   else
      obj_track_->set_max_obj_size(val);
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

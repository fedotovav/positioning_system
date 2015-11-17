#include <map>
#include <fstream>

#include "gui.h"

using namespace std;

// object track settings

size_t   min_h, max_h
       , min_s, max_s
       , min_v, max_v
       , min_obj_size, max_obj_size;

double   brightness_hwr
       , contrast_hwr
       , saturation_hwr
       , hue_hwr
       , gain_hwr
       , exposure_hwr;

double   brightness_swr
       , contrast_swr;

extern void init_maps( gui::settings_t::map_dbl_t & settings_map_dbl, gui::settings_t::map_ui_t & settings_map_ui );

gui::settings_t::settings_t( obj_track_ptr_t & ot ) :
   obj_track_(ot)
{
}

void gui::settings_t::import_settings( string const & file_name )
{
   Node const config = LoadFile(file_name);

   map_dbl_t settings_map_dbl;
   map_ui_t  settings_map_ui;
   
   init_maps(settings_map_dbl, settings_map_ui);

   string setting_name;

   for (size_t i = 0; i < config.size(); ++i)
   {
      setting_name = (config[i])["name"].as<string>();

      for (auto it = settings_map_dbl.begin(); it != settings_map_dbl.end(); ++it)
      {
         if (!it->first.compare(setting_name))
            *(it->second) = (config[i])["value"].as<double>();
      }

      for (auto it = settings_map_ui.begin(); it != settings_map_ui.end(); ++it)
      {
         if (!it->first.compare(setting_name))
            *(it->second) = (config[i])["value"].as<size_t>();
      }
   }
   
   update_settings_values_after_import();
}

void gui::settings_t::export_settings( string const & file_name )
{
   ofstream output_file(file_name);
   Emitter emitter;
   
   map_dbl_t settings_map_dbl;
   map_ui_t  settings_map_ui;
   
   get_settings_values_for_export();
   
   init_maps(settings_map_dbl, settings_map_ui);
   
   emitter << BeginSeq;
   
   for (auto it = settings_map_ui.begin(); it != settings_map_ui.end(); ++it)
   {
      emitter << BeginMap << Newline
              << Key << "name"  << Value << it->first << Key << "value" << Value << *(it->second) 
              << EndMap << Newline;
   }
   
   for (auto it = settings_map_dbl.begin(); it != settings_map_dbl.end(); ++it)
   {
      emitter << BeginMap << Newline
              << Key << "name"  << Value << it->first << Key << "value" << Value << *(it->second) 
              << EndMap << Newline;
   }

   emitter << EndSeq;
   
   output_file << emitter.c_str();
}

void gui::settings_t::get_settings_values_for_export()
{
   min_h = obj_track_->get_min_h();
   max_h = obj_track_->get_max_h();
   min_s = obj_track_->get_min_s();
   max_s = obj_track_->get_max_s();
   min_v = obj_track_->get_min_v();
   max_v = obj_track_->get_max_v();

   min_obj_size = obj_track_->get_min_obj_size();
   max_obj_size = obj_track_->get_max_obj_size();

   brightness_hwr = obj_track_->get_brightness_hwr();
   contrast_hwr   = obj_track_->get_contrast_hwr();
   saturation_hwr = obj_track_->get_saturation_hwr();
   hue_hwr        = obj_track_->get_hue_hwr();
   gain_hwr       = obj_track_->get_gain_hwr();
   exposure_hwr   = obj_track_->get_exposure_hwr();

   brightness_swr = obj_track_->get_brightness_swr();
   contrast_swr   = obj_track_->get_contrast_swr();
}

void gui::settings_t::update_settings_values_after_import()
{
   obj_track_->set_min_h(min_h);
   obj_track_->set_min_s(min_s);
   obj_track_->set_min_v(min_v);
   obj_track_->set_max_h(max_h);
   obj_track_->set_max_s(max_s);
   obj_track_->set_max_v(max_v);

   obj_track_->set_min_obj_size(min_obj_size);
   obj_track_->set_max_obj_size(max_obj_size);
   
   obj_track_->set_brightness_hwr(brightness_hwr);
   obj_track_->set_contrast_hwr(contrast_hwr);
   obj_track_->set_saturation_hwr(saturation_hwr);
   obj_track_->set_hue_hwr(hue_hwr);
   obj_track_->set_gain_hwr(gain_hwr);
   obj_track_->set_exposure_hwr(exposure_hwr);

   obj_track_->set_brightness_swr(brightness_swr);
   obj_track_->set_contrast_swr(contrast_swr);
}
   
void init_maps( gui::settings_t::map_dbl_t & settings_map_dbl, gui::settings_t::map_ui_t & settings_map_ui )
{
   settings_map_ui.insert(make_pair("minimum hue"       , &min_h));
   settings_map_ui.insert(make_pair("minimum saturation", &min_s));
   settings_map_ui.insert(make_pair("minimum value"     , &min_v));
   settings_map_ui.insert(make_pair("maximum hue"       , &max_h));
   settings_map_ui.insert(make_pair("maximum saturation", &max_s));
   settings_map_ui.insert(make_pair("maximum value"     , &max_v));

   settings_map_ui.insert(make_pair("minimum object size", &min_obj_size));
   settings_map_ui.insert(make_pair("maximum object size", &max_obj_size));

   settings_map_dbl.insert(make_pair("brightness hardware", &brightness_hwr));
   settings_map_dbl.insert(make_pair("contrast hardware"  , &contrast_hwr));
   settings_map_dbl.insert(make_pair("saturation hardware", &saturation_hwr));
   settings_map_dbl.insert(make_pair("hue hardware"       , &hue_hwr));
   settings_map_dbl.insert(make_pair("gain hardware"      , &gain_hwr));
   settings_map_dbl.insert(make_pair("exposure hardware"  , &exposure_hwr));

   settings_map_dbl.insert(make_pair("brightness software", &brightness_swr));
   settings_map_dbl.insert(make_pair("contrast software"  , &contrast_swr));
}

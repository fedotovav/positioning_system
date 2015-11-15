BIN_DIR = bin
OBJ_DIR = obj

TARGET = cv_obj_tracking

GUI_DIR       = gui
MOC_DIR       = moc_src
UI_DIR        = ui
OBJ_TRACK_DIR = object_track

MOC_SRCS  = $(GUI_SRC)/gui.h obj_track.h
CPP_SRCS  = $(addprefix $(MOC_DIR)/, $(notdir $(MOC_SRCS:.h=.moc.cpp)))
CPP_SRCS += $(GUI_DIR)/gui.cpp $(OBJ_TRACK_DIR)/obj_track.cpp main.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(CPP_SRCS:.cpp=.o)))

CPP_INCLUDE_FILES = -I/usr/local/include/opencv -I/usr/local/include -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore
CPP_LIBS = -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal -L/usr/lib/x86_64-linux-gnu -lQtCore -lQtGui
CPP_FLG = -std=c++11

all: dir ui $(TARGET)
	
dir: 
	if !(test -d $(BIN_DIR)); then mkdir $(BIN_DIR); fi
	if !(test -d $(OBJ_DIR)); then mkdir $(OBJ_DIR); fi
	if !(test -d $(MOC_DIR)); then mkdir $(MOC_DIR); fi

$(MOC_DIR)/gui.moc.cpp: $(GUI_DIR)/gui.h
	moc $< -o $@

$(MOC_DIR)/obj_track.moc.cpp: $(OBJ_TRACK_DIR)/obj_track.h
	moc $< -o $@

ui:
	uic $(GUI_DIR)/$(UI_DIR)/gui.ui -o $(GUI_DIR)/$(UI_DIR)/gui_ui.h
	uic $(GUI_DIR)/$(UI_DIR)/color_range.ui -o $(GUI_DIR)/$(UI_DIR)/color_range_ui.h
	uic $(GUI_DIR)/$(UI_DIR)/camera_settings.ui -o $(GUI_DIR)/$(UI_DIR)/camera_settings_ui.h

$(TARGET): ui $(OBJ_FILES)
	g++ -g -o $(BIN_DIR)/$(TARGET) $(OBJ_FILES) $(LINK_FLAGS) $(CPP_LIBS) -fopenmp
 
$(OBJ_DIR)/%.o: $(GUI_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(MOC_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(OBJ_TRACK_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: %.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

clean:
	rm -rf $(BIN_DIR)/$(TARGET) $(OBJ_DIR)/*.o $(MOC_SRC)/*.cpp

	
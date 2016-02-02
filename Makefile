BIN_DIR = bin
OBJ_DIR = obj

TARGET = cv_obj_tracking

MOC_DIR		  = moc_src
UI_DIR		  = ui

GUI_DIR		  = gui
CAM_DIR  	  = camera
SETTINGS_DIR      = settings
ROBOT_CONTROL_DIR = robot_control
POS_SYS_DIR	  = pos_sys
HUB_DIR		  = hub

MOC_SRCS  = gui.h pos_sys.h #robot_control.h
CPP_SRCS  = $(addprefix $(MOC_DIR)/, $(notdir $(MOC_SRCS:.h=.moc.cpp)))
CPP_SRCS += $(HUB_DIR)/util.cpp $(HUB_DIR)/hub.cpp $(CAM_DIR)/camera.cpp $(POS_SYS_DIR)/pos_sys.cpp $(SETTINGS_DIR)/settings.cpp $(ROBOT_CONTROL_DIR)/sender.cpp $(GUI_DIR)/gui.cpp main.cpp #$(ROBOT_CONTROL_DIR)/robot_control.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(CPP_SRCS:.cpp=.o)))

CPP_INCLUDE_FILES = -I/usr/local/include/opencv -I/usr/local/include -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include
CPP_LIBS = -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal -L/usr/lib/x86_64-linux-gnu -lQtCore -lQtGui -lyaml-cpp -lserial
CPP_FLG = -std=c++11

all: dir ui moc $(TARGET)
	
dir: 
	if !(test -d $(BIN_DIR)); then mkdir $(BIN_DIR); fi
	if !(test -d $(OBJ_DIR)); then mkdir $(OBJ_DIR); fi
	if !(test -d $(MOC_DIR)); then mkdir $(MOC_DIR); fi

moc:
	moc-qt4 $(GUI_DIR)/gui.h -o $(MOC_DIR)/gui.moc.cpp
	moc-qt4 $(POS_SYS_DIR)/pos_sys.h -o $(MOC_DIR)/pos_sys.moc.cpp
	#moc-qt4 $(ROBOT_CONTROL_DIR)/robot_control.h -o $(MOC_DIR)/robot_control.moc.cpp

ui:
	uic-qt4 $(GUI_DIR)/$(UI_DIR)/gui.ui -o $(GUI_DIR)/$(UI_DIR)/gui_ui.h
	uic-qt4 $(GUI_DIR)/$(UI_DIR)/object_params.ui -o $(GUI_DIR)/$(UI_DIR)/object_params_ui.h
	uic-qt4 $(GUI_DIR)/$(UI_DIR)/camera_settings.ui -o $(GUI_DIR)/$(UI_DIR)/camera_settings_ui.h

$(TARGET): ui $(OBJ_FILES)
	g++ -g -o $(BIN_DIR)/$(TARGET) $(OBJ_FILES) $(LINK_FLAGS) $(CPP_LIBS) -fopenmp
 
$(OBJ_DIR)/%.o: $(GUI_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(MOC_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(CAM_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(SETTINGS_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(ROBOT_CONTROL_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(HUB_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: $(POS_SYS_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

$(OBJ_DIR)/%.o: %.cpp
	g++ -g -c $< -o $@ $(CPP_INCLUDE_FILES) $(CPP_FLG) -fopenmp

clean:
	rm -rf $(BIN_DIR)/$(TARGET) $(OBJ_DIR)/*.o $(MOC_SRC)/*.cpp

	
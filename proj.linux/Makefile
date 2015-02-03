EXECUTABLE = littlerunner

INCLUDES = -I.. -I../Classes -I../../../extensions/ -I../../../external/chipmunk/include/chipmunk -I../../../cocos2dx/actions

SOURCES = main.cpp \
        ../Classes/AppDelegate.cpp \
        ../Classes/HelloWorldScene.cpp \
        ../Classes/Entity/Entity.cpp \
        ../Classes/Entity/Player.cpp \
        ../Classes/Scene/TollgateScene.cpp \
        ../Classes/Entity/Monster.cpp \
        ../Classes/MonsterSelector/MonsterSelector.cpp

COCOS_ROOT = ../../..
include $(COCOS_ROOT)/cocos2dx/proj.linux/cocos2dx.mk

SHAREDLIBS += -lcocos2d
COCOS_LIBS = $(LIB_DIR)/libcocos2d.so

STATICLIBS += ../../../lib/linux/debug/libextension.a

$(TARGET): $(OBJECTS) $(STATICLIBS) $(COCOS_LIBS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: %.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c -g $< -o $@

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c -g $< -o $@

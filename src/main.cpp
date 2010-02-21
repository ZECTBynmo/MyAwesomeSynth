/*
 *  main.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/4/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */
#include "includes.h"
#include "juce_StandaloneFilterWindow.h"

class MyJUCEApp : public JUCEApplication {
public:
	MyJUCEApp() : standaloneFilterWindow(0) { 
		printf("MyJUCEApp()\n");
	}
	~MyJUCEApp() {
		printf("~MyJUCEApp()\n");
	}
	void initialise(const String& commandLine) {
		printf("initialise()\n");
		const String applicationName("My Awesome Synth");
		const String fileNameSuffix("app");
		const String folderName("SonicTransfer");
		ApplicationProperties::getInstance()->setStorageParameters(applicationName,
																 fileNameSuffix,
																 folderName,
																 0,
																 PropertiesFile::storeAsXML);
		standaloneFilterWindow = new StandaloneFilterWindow("My Awesome Synth", 
															Colour::fromRGB(165, 165, 165));
		//standaloneFilterWindow->setUsingNativeTitleBar(true);
		standaloneFilterWindow->setVisible(true);
	}
	void shutdown() {
		printf("shutdown()\n");
		if (standaloneFilterWindow != 0) delete standaloneFilterWindow;
	}
	const String getApplicationName() {
		return T("My Awesome Synth");
	}
	const String getApplicationVersion() {
		return T("1.0");
	}
private:
	StandaloneFilterWindow *standaloneFilterWindow;
};
START_JUCE_APPLICATION (MyJUCEApp)


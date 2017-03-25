local backgroundImageName = "matchthree/background.png"

SceneMain = cpgf.cloneClass(gincu.GSceneWrapper)

SceneMain.doOnEnter = function(me)
	me.addEntity(
		gincu.GEntity()
		.addComponent(gincu.createAndLoadImageComponent(backgroundImageName))
		.addComponent(gincu.GComponentTransform())
	)
	
	local viewSize = me.getPrimaryCamera().getWorldSize()
	local viewWidth = viewSize.width;
	local viewHeight = viewSize.height;

	local buttonSize = port.createSize(200, 60);
	
	local x = viewWidth / 2

	me.addEntity(
		createButton("Back", port.createPoint(x, viewHeight / 2), buttonSize, function(e)
			exitScriptDemo() end
		)
	)
	me.addEntity(createBackButton(function(e) exitScriptDemo() end))
end

SceneMain.doOnExit = function(me)
end


imgui = require("imgui")

function love.update(dt)
imgui.NewFrame()
end

function love.draw()
--imgui.SetNextWindowPos(0, 0)
--imgui.SetNextWindowSize(love.graphics.getWidth(), love.graphics.getHeight())
--if imgui.Begin("DockArea", nil, { "ImGuiWindowFlags_NoTitleBar", "ImGuiWindowFlags_NoResize", "ImGuiWindowFlags_NoMove", "ImGuiWindowFlags_NoBringToFrontOnFocus" }) then
	--imgui.DockSpace(123)

	if imgui.Begin("testando", true) then
	    imgui.End();
	end

	if imgui.Begin("testando2", true) then
	    imgui.End();
	end

	imgui.ShowDemoWindow()

	--imgui.End()
--end
imgui.Render()
end

love.textinput = function(t)
	    imgui.TextInput(t)
	end

 	love.keypressed = function(key)
	    imgui.KeyPressed(key)
	    anykeydown = true
	end

	love.keyreleased = function(key)
	    imgui.KeyReleased(key)
	    anykeydown = false
	end

	love.mousemoved = function(x, y)
	    imgui.MouseMoved(x, y)
	end

	love.mousepressed = function(x, y, button)
	    imgui.MousePressed(button)
	    --Input:mousepressed(x, y, button)
	end

	love.mousereleased = function(x, y, button)
	    imgui.MouseReleased(button)
	    --Input:mousereleased(x, y, button)
	end

	love.wheelmoved = function(x, y)
	    imgui.WheelMoved(y)
	end

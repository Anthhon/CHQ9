function generateRandomString(chars, length)
    local result = ""
    local charsLen = #chars

    for i = 1, length do
        local randomIndex = math.random(charsLen)
        result = result .. chars:sub(randomIndex, randomIndex)
    end

    return result
end

-- Preparing random()
math.randomseed(os.time())

-- Generate random CHQ9 interpreter input
local charset = "HQ+"
local randomCode = generateRandomString(charset, math.random(5))

-- Run 'randomCode' and get it's output from interpreter
local handle = io.popen("./build/hq9+ -c " .. randomCode)
local result = handle:read("*a") -- read all output
handle:close()

-- Show result to user
print(result)
io.flush()

-- Get guess from user
io.write("Which input generated this code?\n>> ")
local guess = io.read()

if guess == randomCode then
    print("Congrats, it's correct!\n");
else
    print("Wrong, try again later!\n");
    print("Right answer was: " .. randomCode)
end


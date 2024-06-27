<html>

<head>
<title>6/21/99 - Creating a game environment</title>
<script LANGUAGE="JavaScript">
 <!--
 if (top.location.href.indexOf("index.htm") == -1) {	
theurl = location.href.toString();
 + theurl + "^2";
 top.location.href = newframe;	
}
 // --> 
</script>
</head>

<body bgcolor="#FFFFFF" topmargin="0" leftmargin="0" marginwidth="0" marginheight="0"><center>

<h1 align="center"><font color="#008000">Creating a Game Environment</font></h1>
<p align="center"><b>The Question:</b></p>
<P>I'm needing some direction (more on the lingo side of things) on making a computer
game similar to &quot;Riven&quot; or &quot;Myst&quot;,  The type of game where you walk
around Pick up stuff and solve puzzles...</P>
<p align="left">&nbsp;</p>
<hr>
<p align="center"><b>The Answer</b></p>
<p>Well, there is no one way to do this, I'll see if I can get you started.&nbsp;
The basic idea of these types of games is that you have an
&quot;environment&quot; built on some type of grid that the user has free
control to walk around and explore.&nbsp; Lets start by looking at the set-up
for the grid itself.&nbsp; Any time you start a project like this make sure to
plan it out on paper first.&nbsp; A little planning at the beginning can save
tons of stress later on.&nbsp; Personally, I like to use number systems, as it
can quickly automate most of the process.&nbsp; I am going to set up a naming
convention for my markers that uses the x position, the y position and the
direction the user is facing.&nbsp; You could do this with graphics and keep it
to one frame, but with puzzles, this can get a little hairy.&nbsp; </p>
<p>My basic marker would then look something like this...</p>
<p>1-1-1</p>
<p>This would be a marker on the grid at 1,1 and facing North.&nbsp; (I use a 4
number system, where 1 is north, 2 is east, etc.)&nbsp; Now that we have our
naming convention, we are ready to start building score and adding markers.&nbsp;
If we were just making 1 or 2 nodes, this would not be a problem, but for a
larger on it can take a lot of time.&nbsp; For this purpose, I have provided a
simple script that will create the markers, name them, and add a &quot;hold on
current frame&quot; script for each.&nbsp; Think of it like this.&nbsp; If you
have a 5X5 grid with 4 directions on each, do you really want to create 100
frames with 100 instances of a script by hand.&nbsp; Here is the basic score
builder code...</p>

<table border="1" cellpadding="0" cellspacing="0">
  <tr>
    <td width="100%">

<p class=NormalText><span style='font-family:Courier;color:#0000C8'>on</span><span
style='font-family:Courier'> buildNavScore numX, numY, holdScriptName<span
style="mso-spacerun: yes"><br>
  </span>xGrid =<span style='color:green'> integer</span>(numX)<span
style="mso-spacerun: yes"><br>
  </span>yGrid =<span style='color:green'> integer</span>(numY)</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
  </span>if</span><span style='font-family:Courier'>
xGrid &gt;<span style='color:gray'> 0</span><span style='color:#0000C8'> and</span>
yGrid &gt;<span style='color:gray'> 0</span><span style='color:#0000C8'> then</span></span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
    </span>beginRecording<span
style="mso-spacerun: yes"><br>
      </span>go</span><span style='font-family:Courier;
color:#0000C8'> to</span><span style='font-family:Courier;color:green'> frame</span><span
style='font-family:Courier;color:gray'> 1</span><span style='font-family:Courier'><span
style="mso-spacerun: yes"><br>
      </span>cycle =<span style='color:gray'> 0</span></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
      </span>repeat with</span><span
style='font-family:Courier'> x =<span style='color:gray'> 1</span><span
style='color:#0000C8'> to</span> xGrid</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
        </span>repeat with</span><span
style='font-family:Courier'> y =<span style='color:gray'> 1</span><span
style='color:#0000C8'> to</span> yGrid</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>repeat with</span><span
style='font-family:Courier'> z =<span style='color:gray'> 1</span><span
style='color:#0000C8'> to</span><span style='color:gray'> 4</span></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
            </span>the</span><span style='font-family:
Courier;color:green'> frameLabel</span><span style='font-family:Courier'> =<span
style='color:green'> string</span>(x) &amp;<span style='color:gray'>
&quot;-&quot;</span> &amp;<span style='color:green'> string</span>(y) &amp;<span
style='color:gray'> &quot;-&quot;</span> &amp;<span style='color:green'> string</span>(z)</span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
            </span>go</span><span style='font-family:
Courier;color:#0000C8'> to</span><span style='font-family:Courier;color:green'>
frame</span><span style='font-family:Courier'> ((cycle *<span style='color:
gray'> 10</span>) +<span style='color:gray'> 5</span>)</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
            </span>the</span><span style='font-family:
Courier;color:green'> frameScript</span><span style='font-family:Courier'> =<span
style='color:green'> member</span>(holdScriptName)<span
style="mso-spacerun: yes"><br>
            </span>cycle = cycle +<span
style='color:gray'> 1</span></span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
            </span>go</span><span style='font-family:
Courier;color:#0000C8'> to</span><span style='font-family:Courier;color:green'>
frame</span><span style='font-family:Courier'> (cycle *<span style='color:gray'>
10</span>)</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>end repeat<span
style="mso-spacerun: yes"><br>
        </span>end repeat<span
style="mso-spacerun: yes"><br>
      </span>end repeat</span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
    </span>endRecording</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
  </span>end if<br>
end&nbsp;<o:p/></span></p>

<p class=NormalText><span style='font-family:Courier;color:#0000C8'>on</span><span
style='font-family:Courier;color:green'> getBehaviorDescription</span><span
style='font-family:Courier;color:#0000C8'> me</span><span style='font-family:Courier'><span
style="mso-spacerun: yes"><br>
  </span>describe =<span style='color:gray'>
&quot;This little script is very helpful for generating a basic grid structure
for a game that utilizes 4 point nodes.<span style="mso-spacerun: yes"> 
</span>Call like this...&quot;</span> &amp;<span style='color:#0000C8'> return</span>
&amp;<span style='color:gray'> &quot;buildNavScore(numberOfXGridPieces,
numberOfYGridPieces, nameOfHoldScript)&quot;<o:p/></span></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
  </span>return</span><span style='font-family:Courier'>
describe<o:p/></span><span style='font-size:12.0pt;font-family:Courier;mso-fareast-font-family:"Times New Roman";
mso-bidi-font-family:"Times New Roman";color:#0000C8;mso-ansi-language:EN-US;
mso-fareast-language:EN-US;mso-bidi-language:HE'><br>
end</span></p>

    </td>
  </tr>
</table>


<p class="MsoNormal">For the purposes of this demo, I chose a simple 3X3 grid
and made a &quot;go to the frame&quot; script called &quot;hold&quot;, then
typed this in the message window...</p>
<p class="MsoNormal">buildNavScore(3, 3, "Hold")</p>
<p class="MsoNormal">A few seconds later, we have our score set up.&nbsp; Now we
need a navigation behavior to move us around in this environment.&nbsp; For this
we can use the last marker we passed to get our current position.&nbsp; I used
the <a href="http://www.mediamacros.com/cgi-bin/webdata_behav.cgi?cgifunction=form&amp;fid=928953503">findLastLabel</a>
behavior to get the current marker name.&nbsp; From there we can separate out
each element and move to the correct new location.&nbsp; Below is the behavior I
used to do this.&nbsp; It is dropped on a &quot;hotspot&quot; and can then be
used across every frame.&nbsp; Here is the basic code...</p>
<table border="1" cellpadding="0" cellspacing="0">
  <tr>
    <td width="100%">

<p class=NormalText><span style='font-family:Courier;color:#0000C8'>property</span><span
style='font-family:Courier'> whichHotSpot,<span style='color:green'> spriteNum</span><![if !supportEmptyParas]>&nbsp;<![endif]><o:p/></span></p>

<p class=NormalText><span style='font-family:Courier;color:#0000C8'>global</span><span
style='font-family:Courier'> maxX, maxY<![if !supportEmptyParas]>&nbsp;<![endif]><o:p/></span></p>

<p class=NormalText><span style='font-family:Courier;color:#0000C8'>on</span><span
style='font-family:Courier;color:green'> getPropertyDescriptionList</span><span
style='font-family:Courier;color:#0000C8'> me</span><span style='font-family:
Courier'><o:p/><span
style="mso-spacerun: yes"><br>
  </span>p_list = [:]<o:p/></span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
  </span>addProp</span><span style='font-family:Courier'>
 p_list,<span style='color:green'> #</span>whichHotSpot, [<span
style='color:green'>#format</span> :<span style='color:green'> #symbol</span>,<span
style='color:green'> #comment</span> :<span style='color:gray'> &quot;What
navigation hotspot:&quot;</span>,<span style='color:green'> #default</span>:<span
style='color:green'> #</span>ahead,<span style='color:green'> #range</span> : [<span
style='color:green'>#</span>ahead,<span style='color:green'> #</span>turnleft,<span
style='color:green'> #</span>turnright,<span style='color:green'> #</span>back]]<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
  </span>return</span><span style='font-family:Courier'>
p_list<o:p/></span><span style='font-family:Courier;color:#0000C8'><br>
end</span><span style='font-family:Courier'><![if !supportEmptyParas]>&nbsp;<![endif]><o:p/></span></p>

<p class=NormalText><span style='font-family:Courier;color:#0000C8'>on</span><span
style='font-family:Courier;color:green'> mouseUp</span><span style='font-family:
Courier;color:#0000C8'> me</span><span style='font-family:Courier'><o:p/><span
style="mso-spacerun: yes"><br>
  </span><span style='color:#C80000'>--get the
current marker<o:p/><br>
</span>
<span
style="mso-spacerun: yes">  </span>currentLoc = findLastLabel()<o:p/><br>
<span
style="mso-spacerun: yes">  </span><span style='color:#C80000'>--set the
delimiter to break the location by<o:p/></span></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
  </span>the</span><span style='font-family:Courier;
color:green'> itemDelimiter</span><span style='font-family:Courier'> =<span
style='color:gray'> &quot;-&quot;</span><o:p/><span
style="mso-spacerun: yes"><br>
  </span>currentX =<span style='color:green'> integer</span>(currentLoc.<span
style='color:green'>item</span>[<span style='color:gray'>1</span>])<o:p/><span
style="mso-spacerun: yes"><br>
  </span>currentY =<span style='color:green'> integer</span>(currentLoc.<span
style='color:green'>item</span>[<span style='color:gray'>2</span>])<o:p/><span
style="mso-spacerun: yes"><br>
  </span>currentD =<span style='color:green'> integer</span>(currentLoc.<span
style='color:green'>item</span>[<span style='color:gray'>3</span>])<o:p/><span
style="mso-spacerun: yes"><br>
  </span>newLocList = [currentX, currentY, currentD]<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
  </span>case</span><span style='font-family:Courier'>
whichHotSpot<span style='color:#0000C8'> of</span> <o:p/></span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
    </span>#</span><span style='font-family:Courier'>ahead:<o:p/><span
style="mso-spacerun: yes"><br>
      </span><span style='color:#C80000'>--go foward
1 based upon the current direction<o:p/></span></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
      </span>case</span><span style='font-family:
Courier'> currentD<span style='color:#0000C8'> of</span><o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>1</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
North<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>2</span>]
= (currentY -<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>2</span>] &lt;<span
style='color:gray'> 1</span><span style='color:#0000C8'> then</span>
newLocList[<span style='color:gray'>2</span>] =<span style='color:gray'> 1</span><o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>2</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
East<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>1</span>]
= (currentX +<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>1</span>] &gt; maxX<span
style='color:#0000C8'> then</span> newLocList[<span style='color:gray'>1</span>]
= maxX<span style="mso-spacerun: yes">  </span><o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>3</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
South<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>2</span>]
= (currentY +<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>2</span>] &gt; maxY<span
style='color:#0000C8'> then</span> newLocList[<span style='color:gray'>2</span>]
= maxY<o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>4</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
West<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>1</span>]
= (currentX -<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>1</span>] &lt;<span
style='color:gray'> 1</span><span style='color:#0000C8'> then</span>
newLocList[<span style='color:gray'>1</span>] =<span style='color:gray'> 1</span><o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
      </span>end case</span><span style='font-family:
Courier'><o:p/></span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
    </span>#</span><span style='font-family:Courier'>turnLeft:
<o:p/><span
style="mso-spacerun: yes"><br>
      </span>newLocList[<span style='color:gray'>3</span>]
= currentD -<span style='color:gray'> 1</span><o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
      </span>if</span><span style='font-family:Courier'>
newLocList[<span style='color:gray'>3</span>] &lt;<span style='color:gray'> 1</span><span
style='color:#0000C8'> then</span> newLocList[<span style='color:gray'>3</span>]
=<span style='color:gray'> 4</span><o:p/></span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
    </span>#</span><span style='font-family:Courier'>turnRight:<o:p/><span
style="mso-spacerun: yes"><br>
      </span>newLocList[<span style='color:gray'>3</span>]
= currentD +<span style='color:gray'> 1</span><o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
      </span>if</span><span style='font-family:Courier'>
newLocList[<span style='color:gray'>3</span>] &gt;<span style='color:gray'> 4</span><span
style='color:#0000C8'> then</span> newLocList[<span style='color:gray'>3</span>]
=<span style='color:gray'> 1</span><o:p/></span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes"><br>
    </span>#</span><span style='font-family:Courier'>back:<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
      </span>case</span><span style='font-family:
Courier'> currentD<span style='color:#0000C8'> of</span><o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>1</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
North<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>2</span>]
= (currentY +<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>2</span>] &gt; maxY<span
style='color:#0000C8'> then</span> newLocList[<span style='color:gray'>2</span>]
= maxY<o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>2</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
East<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>1</span>]
= (currentX +<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>1</span>] &lt;<span
style='color:gray'> 1</span><span style='color:#0000C8'> then</span>
newLocList[<span style='color:gray'>1</span>] =<span style='color:gray'> 1</span><span
style="mso-spacerun: yes">  </span><o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>3</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
South<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>2</span>]
= (currentY +<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>2</span>] &lt;<span
style='color:gray'> 1</span><span style='color:#0000C8'> then</span>
newLocList[<span style='color:gray'>2</span>] =<span style='color:gray'> 1</span><o:p/></span><span style='font-family:Courier;color:gray'><span
style="mso-spacerun: yes"><br>
        </span>4</span><span style='font-family:Courier'>:<o:p/><span
style="mso-spacerun: yes"><br>
          </span><span style='color:#C80000'>--Facing
West<o:p/></span><span
style="mso-spacerun: yes"><br>
          </span>newLocList[<span style='color:gray'>1</span>]
= (currentX -<span style='color:gray'> 1</span>)<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
          </span>if</span><span style='font-family:
Courier'> newLocList[<span style='color:gray'>1</span>] &gt; maxX<span
style='color:#0000C8'> then</span> newLocList[<span style='color:gray'>1</span>]
= maxX<o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
      </span>end case</span><span style='font-family:
Courier'><o:p/></span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes"><br>
  </span>end case</span><span style='font-family:
Courier'><o:p/><span
style="mso-spacerun: yes"><br>
  </span>goTo =<span style='color:green'> string</span>(newLocList[<span
style='color:gray'>1</span>]) &amp;<span style='color:gray'> &quot;-&quot;</span>
&amp;<span style='color:green'> string</span>(newLocList[<span
style='color:gray'>2</span>]) &amp;<span style='color:gray'> &quot;-&quot;</span>
&amp;<span style='color:green'> string</span>(newLocList[<span
style='color:gray'>3</span>])<o:p/><br>
</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes">  </span>if</span><span style='font-family:Courier;
color:green'> marker</span><span style='font-family:Courier'>(goTo) &lt;&gt;<span
style='color:gray'> 0</span><span style='color:#0000C8'> then</span><o:p/><br>
</span><span style='font-family:Courier;color:green'><span
style="mso-spacerun: yes">    </span>go</span><span style='font-family:Courier'>
goTo<o:p/><br>
</span><span style='font-family:Courier;color:#0000C8'><span
style="mso-spacerun: yes">  </span>end if</span><span style='font-family:Courier'><span
style="mso-spacerun: yes">  </span><o:p/><br>
</span><span style='font-family:Courier;color:#0000C8'>end</span><span
style='font-family:Courier'><o:p/></span></p>

<FONT FACE="Courier" COLOR="#0000c8"><P>on</FONT><FONT FACE="Courier" COLOR="#008000"> getBehaviorDescription</FONT><FONT FACE="Courier" COLOR="#0000c8"> me<br>
</FONT><FONT FACE="Courier"><font color="#0000c8">&nbsp;&nbsp; </font>describe =</FONT><FONT FACE="Courier" COLOR="#808080"> "This behavior can be dropped on hot-spots to navigate a
3d/Myst like environment.  Use the Build Environment Script to generate the markers for the environment, then set the maxX and maxY values as
globals.&quot;</FONT><FONT FACE="Courier" COLOR="#0000c8"><br>
</FONT>&nbsp;&nbsp; <FONT FACE="Courier" COLOR="#0000c8">return</FONT><FONT FACE="Courier"> describe<br>
</FONT><FONT FACE="Courier" COLOR="#0000c8">end</FONT></P>

    </td>
  </tr>
</table>

<p>Place this on your hotspots and then set the maxX and maxY globals in your
startMovie handler.&nbsp; This tells the script what the maximum X value and
maximum Y value in the grid is so it will not run beyond its edges.&nbsp;
Technically this could be removed as it also checks for the existence of a
marker before jumping to it, but a little extra error checking never hurt.&nbsp;
If you want a node to be non-existent, just remove its markers.</p>
<p>This is still a pretty simple script.&nbsp; You can add conditions for
skipping markers, making 6 or 8 sided nodes, etc., but this should be a good basic
start.</p>
<p>As for the objects, there are a lot of approaches you can take.&nbsp; You can
add handlers in the first frame of a node to check if the object has been picked
up, and if not, make it visible, but the easiest way (for a few objects) might
be to put each object in a separate channel, then when it is clicked or picked
up, have it added to an inventory list and its channel visibility set to 0.&nbsp;
It will vary for each project, but this is a pretty safe method.</p>
<p>As usual, you can also find all of these behaviors/scripts in the behavior
database.</p>
<p align="center"><a href="/howto.shtml">Return to the article list</a>&nbsp;&nbsp;&nbsp;&nbsp;
<a href="/howdosub.shtml">Submit a Question</a></p>
<p align=center><small>MediaMacros Copyright 1999 <a href="mailto:chuck@mediamacros.com">Chuck
Neal</a></small></p>
</body>
</html>


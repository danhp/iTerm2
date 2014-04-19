/*
 **  PreferencePanel.h
 **
 **  Copyright (c) 2002, 2003
 **
 **  Author: Fabian, Ujwal S. Setlur
 **
 **  Project: iTerm
 **
 **  Description: Implements the model and controller for the preference panel.
 **
 **  This program is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 2 of the License, or
 **  (at your option) any later version.
 **
 **  This program is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with this program; if not, write to the Free Software
 **  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#import <Cocoa/Cocoa.h>
#import "FutureMethods.h"
#import "ProfileModel.h"
#import "ProfileListView.h"
#import "PTYTextViewDataSource.h"
#import "SmartSelectionController.h"
#import "TriggerController.h"
#import "WindowArrangements.h"

extern NSString *const kRefreshTerminalNotification;
extern NSString *const kUpdateLabelsNotification;
extern NSString *const kKeyBindingsChangedNotification;
extern NSString *const kPreferencePanelDidUpdateProfileFields;

// All profiles should be reloaded.
extern NSString *const kReloadAllProfiles;

#define OPT_NORMAL 0
#define OPT_META   1
#define OPT_ESC    2

// Constants for KEY_PROMPT_CLOSE
// Never prompt on close
#define PROMPT_NEVER 0
// Always prompt on close
#define PROMPT_ALWAYS 1
// Prompt on close if jobs (excluding some in a list) are running.
#define PROMPT_EX_JOBS 2

@class iTermController;
@class TriggerController;
@class SmartSelectionController;
@class TrouterPrefsController;

void LoadPrefsFromCustomFolder(void);

@interface PreferencePanel : NSWindowController <
    ProfileListViewDelegate,
    NSTokenFieldDelegate,
    NSWindowDelegate,
    NSMenuDelegate>

@property(nonatomic, readonly) NSString *currentProfileGuid;

+ (PreferencePanel*)sharedInstance;
+ (PreferencePanel*)sessionsInstance;

- (void)openToBookmark:(NSString*)guid;

- (void)updateBookmarkFields:(NSDictionary *)dict;

- (IBAction)showGlobalTabView:(id)sender;
- (IBAction)showAppearanceTabView:(id)sender;
- (IBAction)showBookmarksTabView:(id)sender;
- (IBAction)showKeyboardTabView:(id)sender;
- (IBAction)showArrangementsTabView:(id)sender;
- (IBAction)showMouseTabView:(id)sender;
- (IBAction)setAsDefault:(id)sender;

- (WindowArrangements *)arrangements;
- (void)savePreferences;
- (void)run;
- (float)fsTabDelay;
- (BOOL)trimTrailingWhitespace;
- (int)modifierTagToMask:(int)tag;
- (BOOL)allowClipboardAccess;
- (BOOL)copySelection;
- (BOOL)copyLastNewline;
- (BOOL)legacyPasteFromClipboard;
- (BOOL)threeFingerEmulatesMiddle;
- (BOOL)hideTab;
- (int)tabViewType;
- (int)windowStyle;
- (BOOL)promptOnQuit;
- (BOOL)onlyWhenMoreTabs;
- (BOOL)focusFollowsMouse;
- (BOOL)tripleClickSelectsFullLines;
// Returns true if ANY profile has growl enabled (preserves interface from back
// when there was a global growl setting as well as a per-profile setting).
- (BOOL)enableGrowl;
- (BOOL)cmdSelection;
- (BOOL)optionClickMovesCursor;
- (BOOL)passOnControlLeftClick;
- (BOOL)maxVertically;
- (BOOL)hideTabNumber;
- (BOOL)hideTabCloseButton;
- (BOOL)hideActivityIndicator;
- (BOOL)highlightTabLabels;
- (BOOL)hideMenuBarInFullscreen;
- (BOOL)openBookmark;
- (NSString *)wordChars;
- (BOOL)hideScrollbar;
- (BOOL)showPaneTitles;
- (BOOL)disableFullscreenTransparency;
- (BOOL)smartPlacement;
- (BOOL)adjustWindowForFontSizeChange;
- (BOOL)windowNumber;
- (BOOL)jobName;
- (BOOL)showBookmarkName;
- (BOOL)instantReplay;
- (BOOL)savePasteHistory;
- (BOOL)openArrangementAtStartup;
- (int)irMemory;
- (BOOL)hotkey;
- (short)hotkeyChar;  // Nonzero if hotkey is set validly
- (int)hotkeyCode;
- (int)hotkeyModifiers;
- (NSTextField*)hotkeyField;

- (BOOL)showWindowBorder;
- (BOOL)lionStyleFullscreen;
- (BOOL)dimInactiveSplitPanes;
- (BOOL)dimBackgroundWindows;
- (BOOL)animateDimming;
- (BOOL)dimOnlyText;
- (float)dimmingAmount;
- (BOOL)legacySmartCursorColor;
- (float)legacyMinimumContrast;
- (BOOL)quitWhenAllWindowsClosed;
- (BOOL)useUnevenTabs;
- (int)minTabWidth;
- (int)minCompactTabWidth;
- (int)optimumTabWidth;
- (BOOL)traditionalVisualBell;

// A hidden preference. If set, the scroll wheel sends arrow keys in alt screen mode.
- (BOOL)alternateMouseScroll;
- (float)hotkeyTermAnimationDuration;
- (NSString *)searchCommand;
- (NSTimeInterval)antiIdleTimerPeriod;
- (void)changeFont:(id)fontManager;
- (void)showBookmarks;
- (void)underlyingBookmarkDidChange;
- (int)openTmuxWindowsIn;
- (BOOL)autoHideTmuxClientSession;
- (int)tmuxDashboardLimit;

- (int)control;
- (int)leftOption;
- (int)rightOption;
- (int)leftCommand;
- (int)rightCommand;
- (BOOL)isAnyModifierRemapped;
- (int)switchTabModifier;
- (int)switchWindowModifier;

- (BOOL)hotkeyTogglesWindow;
- (BOOL)hotkeyAutoHides;
- (BOOL)dockIconTogglesWindow;
- (NSTimeInterval)timeBetweenBlinks;
- (BOOL)autoCommandHistory;
- (void)setAutoCommandHistory:(BOOL)value;

- (Profile*)hotkeyBookmark;

- (BOOL)importColorPresetFromFile:(NSString*)filename;

@end

function [y1] = NN_model(x1)
%NN_MODEL neural network simulation function.
%
% Auto-generated by MATLAB, 02-Sep-2020 21:52:56.
% 
% [y1] = NN_model(x1) takes these arguments:
%   x = 28xQ matrix, input #1
% and returns:
%   y = 4xQ matrix, output #1
% where Q is the number of samples.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = [-0.824769756919744;-0.819976042969736;-1.70999023407952;-1.43998046815112;-1.0526900285858;-1.05003723258287;-4.06997238075402;-1.69996124148957;-1.14206277148681;-1.01999633777675;-2.20997085482274;-2.29994506668119;24.9333793653043;25.100093081339;24.9000366220974;-1.19998168889358;0.0142092895799671;0.0160004272591366;0;-7.50890102847084;80.0002136295175;80.0002136295175;80.0002136295175;-15.9998779259523;48.5002975555488;49.0004119999602;48.0001831111374;-36.9994659261463];
x1_step1.gain = [0.998119037853208;0.523566128146517;0.69443623945377;0.638990034198243;1.38152875796992;0.706718597517416;0.501260973401298;0.598813967496437;0.978409229338132;0.630919716107269;0.645169261436417;0.471709589163294;0.183839838415527;0.183487805439876;0.183488447623576;0.833346049573499;0.221939994879772;0.219035889270659;0.221951400615034;0.139074791653139;0.100001068158997;0.100001068158997;0.100001068158997;0.0869574448040891;0.0233918942735431;0.0235295258136906;0.023255863469856;0.0243906887073402];
x1_step1.ymin = -1;

% Layer 1
b1 = [-1.5572179460371777804;1.2168020273141078036;0.79541332676931142398;-0.48515367341588300221;-0.16569741469592558225;0.12409896309423197602;0.36872497943582110969;-0.78864247732453751638;-1.1320096766484577522;-1.5370997774376427003];
IW1_1 = [0.19181162196932083353 -0.036091991805562766149 -0.48606838222823456341 0.060174555356455362853 -0.27803515267805534172 -0.15047787794407752049 -0.073039191330738814645 0.10030698519932755575 0.095302662173363347775 0.23230564804955708413 -0.15409133378573422468 -0.32250728116140320312 -0.48339134787306176078 -0.066982296674817837223 0.38850784951659572686 0.1849310574681483077 -0.33641048401284612268 -0.28964071637144445104 0.3102978060496401902 -0.22897917533915193578 0.31318172425381279877 -0.15330700980282238599 0.43179895302178639138 -0.33145752024228025689 -0.27244014263361560069 -0.41393692315503283208 -0.31117837409212245614 0.36354685323829999399;-0.35399053011167425087 0.13029136402194071986 0.2177475126278443085 -0.38406195702171708195 -0.34471752933457755486 -0.5528969016001971104 -0.050848163272603649765 -0.034907622302848870244 0.46731157899770137121 0.25822419123971607213 0.089450904682306708882 0.17096043366826127463 -0.35075316602906847496 0.48025510178805308481 -0.47697797809280245707 -0.39078467065279143267 0.29400787931672939246 -0.21389294244613304974 -0.39881610436075481951 0.064557179493690705629 -0.19556570212501414585 -0.15857091942940915175 -0.010141675149090138841 0.18378423077316660694 -0.18752422692373699187 0.12082983007448672153 -0.098662103572742299029 -0.048873866699260679058;-0.34097537040151393306 -0.028278108406140953918 0.10051892914228577336 0.15408048489630049582 0.074455875523142256434 -0.25508310878647794118 -0.020717423224141284094 -0.44381298714185796195 -0.10583976279459390846 -0.29427961768395061171 0.33019698325297547337 0.039160056107284409166 0.072520475766478922908 0.15630219050968804928 -0.30957922869041348823 -0.29126206390035352944 0.32212446625903934372 0.30343991063883340997 0.4397264276871815647 -0.31802521361238100805 0.44309739223010846665 0.079462823778106470018 -0.35036408862147100374 -0.15709012441789896308 -0.36578878647895685106 -0.038452295499884284191 0.44709090002720613954 -0.46702716227989859998;0.4451046440868171028 0.24938463845460895341 0.27888005253644310155 0.45761989186955376319 0.4193411309087178851 0.078945459756713395882 0.15832986646731794789 -0.14439475761364042872 -0.13854248438050939529 0.038264778515248648594 0.53913565460065104862 -0.31344298427448485933 -0.03784988657256793676 -0.055742513839513785356 0.36170994411172935346 0.25822747281909036454 0.32491533091956781298 -0.054480528644631535939 -0.30198388007260418275 0.052600210211785743131 0.048388088153606914621 -0.38732352924823137963 -0.33362705076798793158 -0.37931060910723840562 0.18567503145844108103 0.37597849368145402904 -0.055884942037109863744 -0.15903201451620724294;0.14856894690165839412 -0.041760040933110753603 -0.38331191154097815632 0.17088534327383086975 -0.41057571894797145751 -0.14020400785382428066 -0.16394443539482958516 0.089124629874925198614 0.40358589306209774472 -0.055679848562102195186 0.35395744489837122071 -0.032465921329794256156 0.45298902039302174627 -0.33924275459726843662 -0.023763089457007176286 -0.005912375704876186161 -0.35078551683826297847 0.30008856989579174579 -0.16662888566294123405 0.44902161642263643815 0.09484204267505212671 0.23594797415746743274 0.38514167566781437602 -0.1611373036940223491 -0.35798729085271241424 -0.28803944248051766008 0.41708462562172843313 -0.23416945583028014877;0.5680904962381192469 0.038138463033568464899 -0.20325475114250637909 0.55743343221861840764 0.45516787694546179122 -0.39516811455384831531 0.1706689101795465513 -0.22233065240019875275 0.026430549217224198061 -0.07826674732712897431 -0.060245277766112180495 -0.10688370122155620157 -0.11378976586028934082 -0.30046926741053742171 0.13259890990196326888 0.094420083774798102549 -0.1544391970338763187 0.14869700905646998645 -0.35800922672912172118 0.21233963984181172813 -0.33920789803490319914 0.052191700134662413757 0.53699333859585229867 -0.40169386535441581332 -0.0084296348116940506001 -0.21509210377461437935 0.18558519012000124215 0.38217054467764893788;0.01634687707488342856 -0.22238907769743906928 -0.16621704556317781765 -0.11013919900886025294 0.31308106140470498557 0.010973913298922936821 -0.4480048533607304817 0.2409495794891997611 0.45719245198875868574 0.078672186050920939193 -0.39114342524214268382 -0.16282831147204809841 -0.14114919667114500523 0.21319571928536878991 -0.055350365267281105564 -0.50021379556114886622 0.35861078844401961252 0.16539778439789221132 0.44202228242739527442 0.31740549322105054975 -0.4501193342628898586 -0.47136403697891027242 0.16794303076398470198 0.27537557764951825501 0.2664551261944930749 0.4799357610998424839 0.03313541816557758618 0.24235751221966916891;-0.1138503465284865096 -0.40475175166052168585 -0.094274672933989528412 -0.11529914332345417294 -0.45562731299863146184 -0.19987017488641103946 0.28739254908282851897 -0.14406441102371292384 0.44862521065404514786 -0.091144479813066295315 0.054689407138397372332 0.39123234773471377013 0.3382498451667304562 -0.34155141964203050708 -0.4386387339367556204 0.088966064833409616575 -0.3402658790834849345 -0.31696872610438653339 0.38638992074832517742 0.21727047062297760727 0.28648064365108572016 -0.041044021519665338515 0.25210574935263224683 -0.4248753631328611724 0.17971420330845011559 0.11799645985961375316 -0.10802205066979883585 -0.012981936693867464697;-0.078518453766748957934 0.1293416816500271016 -0.42174182208700949914 0.19267910739442811741 0.26175509550595676966 -0.036887447977295595436 0.021231940841560700828 -0.10121150220487942772 -0.16415782642217960352 -0.26568620561019651305 -0.43905338933102205923 -0.44190058439619073205 -0.039699283298810915388 0.12613706667639332237 0.044759105549327007911 0.47499205601574351343 0.4493137173281384622 0.21513483347388992484 0.47740623706279228244 0.25741047949907730485 -0.13508773392654777057 0.48068706938074190482 0.013376919656050501387 0.37850064529011362424 -0.17537612645863073779 -0.33525615946726783356 0.44075207456385823157 0.023550657100765915591;-0.23645240571593700851 0.24312124610891586163 -0.22012665565865086048 0.017960413688677692723 0.34812807880049928544 -0.10718320046695441194 -0.24818600263255274907 -0.25494657832117972873 0.14389448441094604414 -0.14684804893465314146 0.43019584412650091476 0.0087184835612391167747 -0.3119364560547528975 -0.047343446062064156732 0.30105845150456517212 0.38384903429254313423 -0.17830656981603906774 0.24615886547906057347 0.31963730501653725424 0.280825881045049075 0.35461039589186210685 -0.35744471952362194545 0.36338886711896839499 -0.3220458608577148607 -0.32141041270020137555 0.41264005965577155166 -0.38373526041572719736 0.36103833729235007555];

% Layer 2
b2 = [0.52322847399848126937;-0.87272424858992925234;0.6359172553466864164;-0.63617411104717358494];
LW2_1 = [-0.30812978630215465126 -0.59597655028372509278 0.18657528624189964606 0.55321022329323554789 0.31913521614601980669 0.89584993562945303136 0.81919156793206171496 0.76648881340492136527 -0.84735248960166520416 0.4617685827127750442;0.33323753657294691299 0.050669459989600193484 -0.42149130455687311425 -0.54124375797092671991 -0.77192062298348929072 -0.40666253282915842959 -0.65583578395133801386 -0.54959777798305287089 0.14242794531839125804 -0.25190201776301551773;-0.5719794251591466816 -0.55020243771746901729 -0.90648144076745629238 -0.67198975793296356063 -0.78128887331739871325 -0.3676573191572721222 0.36257721908771473052 -0.21311305223678125853 0.068913659822899903107 0.49656438302438132837;-0.54955585031607978586 0.1851447485049842745 -0.34068934108386567106 0.47728845590741314497 -0.077094929387010929789 -0.36542096995087902656 -0.39427310858773639834 0.77363128307911988024 0.80654541947715541195 -0.42770581308346977689];

% Output 1
y1_step1.ymin = -1;
y1_step1.gain = [2;2;2;2];
y1_step1.xoffset = [0;0;0;0];

% ===== SIMULATION ========

% Dimensions
Q = size(x1,2); % samples

% Input 1
xp1 = mapminmax_apply(x1,x1_step1);

% Layer 1
a1 = tansig_apply(repmat(b1,1,Q) + IW1_1*xp1);

% Layer 2
a2 = repmat(b2,1,Q) + LW2_1*a1;

% Output 1
y1 = mapminmax_reverse(a2,y1_step1);
end

% ===== MODULE FUNCTIONS ========

% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings)
  y = bsxfun(@minus,x,settings.xoffset);
  y = bsxfun(@times,y,settings.gain);
  y = bsxfun(@plus,y,settings.ymin);
end

% Sigmoid Symmetric Transfer Function
function a = tansig_apply(n,~)
  a = 2 ./ (1 + exp(-2*n)) - 1;
end

% Map Minimum and Maximum Output Reverse-Processing Function
function x = mapminmax_reverse(y,settings)
  x = bsxfun(@minus,y,settings.ymin);
  x = bsxfun(@rdivide,x,settings.gain);
  x = bsxfun(@plus,x,settings.xoffset);
end

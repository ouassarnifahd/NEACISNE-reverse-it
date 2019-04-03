library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity freq is
    Port ( clk : in STD_LOGIC;
           TTL : in STD_LOGIC;
           seg : out STD_LOGIC_VECTOR (6 downto 0);
           an : out STD_LOGIC_VECTOR (7 downto 0);
           dp : out STD_LOGIC);
end freq;

architecture Behavioral of freq is
    signal TTL_mef_s : STD_LOGIC;
    signal valid_s : STD_LOGIC;
    signal raz_s : STD_LOGIC;
    signal verr_s : STD_LOGIC;
    signal freq_s : STD_LOGIC_VECTOR(15 downto 0);
    signal data_s : STD_LOGIC_VECTOR(15 downto 0);

component m_e_form is
    Port ( clk : in STD_LOGIC;
           TTL : in STD_LOGIC;
           TTL_mef : out STD_LOGIC);
end component;

component controle is
    Port ( clk : in STD_LOGIC;
           valid : out STD_LOGIC;
           raz : out STD_LOGIC;
           verr : out STD_LOGIC);
end component;

component compteur0 is
    Port ( clk : in STD_LOGIC;
        TTL_mef : in STD_LOGIC;
        valid : in STD_LOGIC;
        raz : in STD_LOGIC;
        freq : out STD_LOGIC_VECTOR (15 downto 0));
end component;

component verrou is
    Port ( clk : in STD_LOGIC;
           verr : in STD_LOGIC;
           freq : in STD_LOGIC_VECTOR (15 downto 0);
           freq_verr : out STD_LOGIC_VECTOR (15 downto 0));
end component;

component affichage is
    Port ( clk : in STD_LOGIC;
           data : in STD_LOGIC_VECTOR (15 downto 0);
           seg : out STD_LOGIC_VECTOR (6 downto 0);
           an : out STD_LOGIC_VECTOR (7 downto 0);
           dp : out STD_LOGIC);
end component;

begin

u1: m_e_form port map(
    clk => clk,
    TTL => TTL,
    TTL_mef => TTL_mef_s);
    
u2: controle port map(
    clk => clk,
    valid => valid_s,
    raz => raz_s,
    verr => verr_s);
    
u3: compteur0 port map(
    clk => clk,
    TTL_mef => TTL_mef_s,
    valid => valid_s,
    raz => raz_s,
    freq => freq_s);
    
u4: verrou port map(
    clk => clk,
    freq => freq_s,
    verr => verr_s,
    freq_verr => data_s);
    
u5: affichage port map(
    clk => clk,
    data => data_s,
    seg => seg,
    an => an,
    dp => dp);

end Behavioral;
